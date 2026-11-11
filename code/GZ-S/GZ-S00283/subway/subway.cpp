//李杜文谦 GZ-S00283 清镇市广大实验学校 
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e4+15,INF=0x3f3f3f3f3f3f3f3f;
int n,m,d,q,c;
int s[515][N];
int w[N];
int quq[50*N];
int h=1,t,x[50*N],y[50*N],ma=INT_MAX;
bool vis[515][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(s,0x3f,sizeof(s));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int a,t;
		int p;
		cin>>p;
		for(int j=1;j<=p;j++){
			cin>>a>>t;
			s[i][a]=t;
		}
	} 
	while(q--){
		ma=INT_MAX;
		h=1,t=0;
		int ans=0;
		int a,b;
		cin>>a>>b;
		ans=w[a]+w[b];
		for(int i=1;i<=n;i++){
			if(s[i][a]!=INF){
				quq[++t]=s[i][a];
				x[t]=i,y[t]=a;
				while(h<=t){
					
					for(int l=1;l<=m;l++){
						if(quq[h]+s[x[h]][l]<ma&& !vis[x[h]][l]){
							quq[++t]=quq[h]+s[x[h]][l];
							x[t]=x[h],y[t]=l;
							vis[x[h]][l]=1;
						}
						if(l==b){
							ma=min(ma,quq[h]+s[x[h]][l]+ans);
						}
					}
					for(int r=1;r<=n;r++){
						if(quq[h]+s[r][y[h]]<ma&& !vis[r][y[h]]){
							quq[++t]=quq[h]+s[r][y[h]];
							x[t]=r,y[t]=y[h];
							vis[r][y[h]]=1;
						}
					}
					vis[x[h]][y[h]]=0;
					h++;
				}
			}
		}
		cout<<ma<<'\n';
	}
	return 0;	
}
