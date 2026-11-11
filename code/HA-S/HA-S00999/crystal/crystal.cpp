#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,ans;
ll a[N],cf[N],ccf[N],cff[N],fc[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		cf[i]=a[i]-a[i-1];
	}
	for(int i=n;i>=2;i--){
		ccf[i]=cf[i]+ccf[i+1];
	}
	for(int i=n;i>=2;i--){
		cff[i]=cff[i+1]+ccf[i];
	}
	for(int i=n;i>=2;i--){
		fc[i]=fc[i+1]+cf[i]*(i-1);
	}
	for(int i=2;i<=n;i++){
		ll l=1,r=i-1;
		while(l<=r){
			ll mid=(l+r)/2;
			if(cff[mid+1]-fc[i+1]<=m){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1ll);
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
