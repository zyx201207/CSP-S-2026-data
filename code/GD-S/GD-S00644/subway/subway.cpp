#include<bits/stdc++.h>
using namespace std;
const int MAXN=605;
int c,n,m,d,q,k,a,t,x,y;//n线路数  m地铁站数  q问数  a站  t时 
int w[MAXN],st,f[MAXN][MAXN];
struct G{
	int t,w;
};
vector<G> g[MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	st=m;
	for(int i=1;i<=st+n;i++){
		for(int j=1;j<=st+n;j++){
			if(i!=j)
				f[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		st++;
		for(int i=1;i<=k;i++){
			cin>>a>>t;
			f[a][st]=t;
			f[st][a]=t;
		}
	}
	for(int k=1;k<=st;k++){
		for(int i=1;i<=st;i++){
			for(int j=1;j<=st;j++){
				if(f[i][k]!=-1 && f[k][j]!=-1){
					if(f[i][j]==-1)
						f[i][j]=f[i][k]+f[k][j];
					else
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}

