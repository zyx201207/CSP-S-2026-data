#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=502,M=5e5+7;
int n,m,q;
int w[M];
struct s{
	int s,w;
};
vector<s>sub[N];
vector<s>bel[M];
int to[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int sta,walk;
		for(int j=1;j<=k;j++){
			cin>>sta>>walk;
			bel[sta].push_back({i,walk});
			sub[i].push_back({sta,walk});
		}
	}
	memset(to,0x3f,sizeof to);
	for(int i=1;i<=m;i++){
		int s=bel[i].size();
		for(int j=0;j<s;j++){
			int x=bel[i][j].s,w=bel[i][j].w;
			for(int k=0;k<s;k++){
				if(j==k){
					to[j][k]=0;
					continue;
				}
				int y=bel[i][k].s,_w=bel[i][k].w;
				to[x][y]=to[y][x]=min(to[x][y],w+_w);
			}
		}
	} 
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<to[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				to[i][j]=min(to[i][j],to[i][k]+to[k][j]);
			}
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3fll;
		for(s &sub:bel[x]){
			int p=sub.s,_w=sub.w;
			for(s &sub2:bel[y]){
				int p2=sub2.s,_w2=sub2.w;
				ans=(to[p][p2]+_w+_w2<ans?to[p][p2]+_w+_w2:ans); 
			}
		}      
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
} 
