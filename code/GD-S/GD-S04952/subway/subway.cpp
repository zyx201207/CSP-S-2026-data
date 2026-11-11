#include <bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
const int MAXM= 500005; 
int w[MAXM]={};
int line[MAXM][25];
long long up[MAXM][25];
int pre[MAXM]={};
long long e[505][505]={};
int main()
{	
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	// Floyd
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	} 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			line[a][++pre[a]]=i;
			up[a][pre[a]]=t;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)e[i][j]=0x3f3f3f3f3f3f3f;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=pre[i];j++){
			for(int k=1;k<=pre[i];k++){
				e[line[i][j]][line[i][k]]=min(up[i][j]+up[i][k], e[line[i][j]][line[i][k]]);
				if(j==k)e[line[i][j]][line[i][k]]=0;
			}
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	while(q--){
		int fromx,tox;
		cin>>fromx>>tox;
		long long ans=0x3f3f3f3f3f3f3f;
		for(int i=1;i<=pre[fromx];i++){
			for(int j=1;j<=pre[tox];j++){
				ans=min(ans,e[line[fromx][i]][line[tox][j]]+up[fromx][i]+up[tox][j]);
			}
		}
		cout<<ans+w[fromx]+w[tox]<<endl;
	}
	
	return 0;
}
