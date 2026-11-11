//GZ-S00262 ³ÂÑô½õ
#include<bits/stdc++.h>
using namespace std;
int a[200010];
int f[5010][5010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	int din=0,dax=0 ;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		dax=max(dax,a[i]-a[i-1]);
		din=min(din,a[i]-a[i-1]);
	}
	if(din==dax){
		for(int i=1;i<=n;i++){
			if(i*(i-1)/2<=m) ans=max(ans,i);
		}
		cout<<ans;
		return 0;
	}
	for(int r=1;r<=n;r++){
		for(int l=r-1;l>=1;l--){
			f[l][r]=f[l+1][r]+(a[r]-a[l]);
			//cout<<l<<' '<<r<<' '<<f[l][r]<<endl;
			if(f[l][r]<=m) ans=max(ans,(r-l+1));
		}
	}
	cout<<ans;
	return 0;
}
