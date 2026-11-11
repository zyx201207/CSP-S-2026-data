#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10; 
const int INF=0x3f3f3f3f;
int c,n,m,d,q,w[M],p[M],dis[N][N],sss[N];
vector<int>g[M];
vector<int>a[N];
vector<int>t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis)); 
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;cin>>k;
		a[i].push_back(0);
		int cc=0;
		for(int j=1;j<=k;j++){
			int ss;
			cin>>ss>>sss[j];
			a[i].push_back(ss);
			cc=max(cc,a[i][j]);
		}
		for(int j=0;j<=cc;j++) t[i].push_back(0);
		for(int j=1;j<=k;j++){
			t[i][a[i][j]]=sss[j];
			g[a[i][j]].push_back(i);
			if(p[a[i][j]]==0){
				p[a[i][j]]=i;
			}else{
				int val=t[p[a[i][j]]][a[i][j]]+t[i][a[i][j]];
				if(dis[i][p[a[i][j]]]>val){
					dis[i][p[a[i][j]]]=val;dis[p[a[i][j]]][i]=dis[i][p[a[i][j]]];
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(dis[i][k]>INF||dis[k][j]>INF) continue;
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		int ans=INF;
		for(int i:g[x]){
			for(int j:g[y]){
				int sum=w[x]+w[y];
				if(i==j){
					sum+=t[i][x]+t[i][y];
					ans=min(ans,sum);
					continue;
				}
				sum+=dis[i][j];
				sum+=t[i][x]+t[j][y];
				ans=min(ans,sum);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
