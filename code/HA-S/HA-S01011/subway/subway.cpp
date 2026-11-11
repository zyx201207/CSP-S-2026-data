#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2e4+5,N=5e5+5;
ll c,n,m,d,p,s[N],a,b,dis[505][M],sta=0,vis[505][M],st,se,q,f[505][M],bk[505][M];
ll poss[505][M];
ll dis2[3][N],vis2[3][N],f2[3][N],bk2[3][N];
struct edge{
	ll to,time;
};
struct node{
	ll to,time;
	bool operator <(const node &l)const{return time<l.time;}
};
vector<edge>vt[N];
vector<edge>vt2[N];
priority_queue<node>sq;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n<=2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)dis2[i][j]=0x3f;
		for(int i=1;i<=m;i++)
			cin>>s[i];
		for(int i=1;i<=n;i++){
			cin>>f2[i][0];
			for(int j=1;j<=f2[i][0];j++){
				cin>>a>>b;
				f2[i][j]=a;
				bk2[i][j]=b;
				vt[a].push_back({i,b});
				vt2[i].push_back({a,b});
			}	
		}
		for(int o=1;o<=n;o++){
			for(int g=1;g<=f2[o][0];g++){
				sq.push({f2[o][g],bk2[o][g]});
				dis2[o][f2[o][g]]=bk2[o][g];
			}
			while(!sq.empty()){
				node u=sq.top();
				sq.pop();
				if(vis[o][u.to])continue;
				vis[o][u.to]=1;
				for(int i=0;i<vt[u.to].size();i++){
					edge v=vt[u.to][i];
					for(int j=0;j<vt2[v.to].size();j++){
						edge k=vt2[v.to][j];
						if(k.to==u.to)continue;
						if(dis2[o][k.to]>u.time+v.time+k.time){
							dis2[o][k.to]=u.time+v.time+k.time;
							sq.push({k.to,dis2[o][k.to]});
						}
				}
					}
			}
		}
		ll minn=1e18;
		for(int i=1;i<=q;i++){
			cin>>st>>se;
			minn=1e18;
			for(int j=1;j<=n;j++){
				minn=min(minn,dis2[j][se]+dis2[j][st]);
			}
			cout<<minn+s[st]+s[se]<<"\n";
		}
		return 0;
	}else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)dis[i][j]=0x3f;
		for(int i=1;i<=m;i++)
			cin>>s[i];
		for(int i=1;i<=n;i++){
			cin>>f[i][0];
			for(int j=1;j<=f[i][0];j++){
				cin>>a>>b;
				f[i][j]=a;
				bk[i][j]=b;
				vt[a].push_back({i,b});
				vt2[i].push_back({a,b});
			}	
		}
		for(int o=1;o<=n;o++){
			for(int g=1;g<=f[o][0];g++){
				sq.push({f[o][g],bk[o][g]});
				dis[o][f[o][g]]=bk[o][g];
			}
			while(!sq.empty()){
				node u=sq.top();
				sq.pop();
				if(vis[o][u.to])continue;
				vis[o][u.to]=1;
				for(int i=0;i<vt[u.to].size();i++){
					edge v=vt[u.to][i];
					for(int j=0;j<vt2[v.to].size();j++){
						edge k=vt2[v.to][j];
						if(k.to==u.to)continue;
						if(dis[o][k.to]>u.time+v.time+k.time){
							dis[o][k.to]=u.time+v.time+k.time;
							sq.push({k.to,dis[o][k.to]});
						}
				}
					}
			}
		}
		ll minn=1e18;
		for(int i=1;i<=q;i++){
			cin>>st>>se;
			minn=1e18;
			for(int j=1;j<=n;j++){
				minn=min(minn,dis[j][se]+dis[j][st]);
			}
			cout<<minn+s[st]+s[se]<<"\n";
		}
	}	
	
	return 0;
}