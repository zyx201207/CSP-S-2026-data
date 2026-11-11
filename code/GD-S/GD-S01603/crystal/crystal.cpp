#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10; 
int n;
//0 1 2 3 3 4    2
ll m,ans=1,a[N],b[N],l,r;
//bool chk(ll x){
//	int sum=0,cnt=0;
//	for(int i=1;i<=n;i++){
//		if(a[i]>=x){
//			break;
//		}
//		sum+=x-a[i];
//		cnt++;
//		if(sum>m){
//			cnt-=1;
//		}
//	}
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<n;i++){
//		b[i]=a[i+1]-a[i];
//	}
//	sort(b+1,b+n+1);
	l=1,r=1;
	ll sum=0,cnt=1;
	while(l<=r&&r<n){
//		cout<<l<<" "<<r<<" "<<sum<<endl;
		if(sum+(a[r+1]-a[r])*(r-l+1ll)<=m){
			sum+=(a[r+1]-a[r])*(r-l+1ll);
			cnt++;
			r++;
		}else{
			ans=max(ans,cnt);
			l++;
			cnt--;
			sum-=a[r]-a[l];
		}
	}
	ans=max(ans,cnt);
	cout<<ans;
	return 0;
} 
