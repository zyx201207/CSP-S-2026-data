#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=310,inf=0x3f3f3f3f3f3f3f3f;
int tsk,t,n,d,x[N],ans,c[N][N],p[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>tsk>>t;
	while(t--){
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(x[i]-x[j])<=d)c[i][j]=p[i][j]=1;
				else c[i][j]=inf,p[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)c[i][i]=1,p[i][i]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(c[j][k]>c[j][i]+c[i][k])c[j][k]=c[j][i]+c[i][k],p[j][k]=p[j][i]*p[i][k];
					else if(c[j][k]==c[j][i]+c[i][k])p[j][k]+=p[j][i]*p[i][k];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(p[i][j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
