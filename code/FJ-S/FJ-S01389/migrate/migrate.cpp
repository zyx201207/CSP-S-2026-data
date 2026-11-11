#include<bits/stdc++.h>
#define int long long
using namespace std;
long long c,t,n,a[5005],d,p[5005][5005],ans;//p最少几步 
bool b[5005];
void dfs(){
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			for(int k=i+1;k<=j-1;k++){
				if((p[i][k]||p[k][j])&&p[i][k]!=-1&&p[k][j]!=-1)p[i][j]=max((int)1,p[i][k])+max((int)1,p[k][j]);
			}
			if(p[i][j]==2)ans++;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<=n;j++){
				p[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			int j=i+1;
			for(;j<=n&&a[i]+d>=a[j];j++){
			}
			if(a[i]+d<a[j]||(j>n&&a[i]+d==a[j-1]))p[i][j-1]=1; 
			if(a[i]+d<a[j])p[i][j]=-1;
		}
		dfs();
		cout<<ans<<'\n';
	return 0;
}
