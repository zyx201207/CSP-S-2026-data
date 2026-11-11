#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll a[N];
ll sum[N];
int erfen(int x){
	int l=1,r=x;
	while(l<r){
//		cout<<l<<" "<<r;
		int mid=(l+r)/2;
		if((a[x]*(x-mid)-sum[x-1]+sum[mid-1])>m){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return l;
} 
int ans,cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
//		cout<<a[i]<<" "<<sum[i]<<"\n";
//		cout<<((a[i]*(i-1))-sum[i-1])<<"\n";
//		if((a[i]*(i-1))-sum[i-1]>m){
//			cout<<i-1;
//			return 0;
//		}
		if(a[i]==a[i-1]){
			cnt++;
		}else{
			ans=max(cnt,ans);
			cnt=i-erfen(i)+1;
//			cout<<erfen(i)<<"\n";
		}
	}
	ans=max(cnt,ans);
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9
¶þ·Ö 
5 8
-3 -1 2 2 7
*/
