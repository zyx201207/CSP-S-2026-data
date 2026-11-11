#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m;
ll a[N];
ll b[N];
ll sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		ll ans=i;
//		cout<<"   i="<<i<<"\n";
		while(l<=r){
			int mid=(l+r)>>1;
//			cout<<"l="<<l<<" r="<<r<<"\n";
//			cout<<"mid="<<mid<<"\n";
//			cout<<"a[i]="<<a[i]<<" (i-mid)="<<i-mid<<" ";
//			cout<<"b[i-1]="<<b[i-1]<<" b[mid-1]="<<b[mid-1]<<"\n";
			if(a[i]*(i-mid)-(b[i-1]-b[mid-1])<=m){
				ans=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
//		cout<<"ans="<<ans<<"\n";
		sum=max(sum,i-ans+1);
	}
	cout<<sum;
} 
