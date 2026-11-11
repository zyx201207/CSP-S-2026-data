//GZ-S00237ÔøÖÂÔ¶ 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const N=5e5+5;
ll a[N],f[N][2],d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	f[1][0]=0,f[1][1]=0;
	for(int i=2;i<=n;i++){
		f[i][1]=a[i]-a[i-1];
		f[i][0]=f[i-1][0]+f[i][1];
		d[i]=d[i-1]+f[i][1];
	}
	for(int i=n;i;i--){
		if(d[i]<=m){
			ans=i;
			break;
		}
	}
	cout<<ans;
	return 0;
}
