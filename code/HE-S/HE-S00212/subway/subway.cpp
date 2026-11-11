#include<bits/stdc++.h>
using namespace std;
struct subway{int stop,t;};
int c,n,m,d,q;
const int MAXN=550;
const int MAXM=5e5+800;
const int INF=0x3f3f3f3f;
int w[MAXM],sid[MAXM];
bool p[MAXM];
vector<subway> vt[MAXM];
vector<int> line[MAXN];
int djstl(int root,int ed){
	memset(sid,0x3f,sizeof(sid));
	memset(p,0,sizeof(p));
	sid[root]=0;p[root]=1;
	int mid=root;
	for(int i=2;i<=m;++i){
		for(int j=0;j<line[mid].size();++j){
			for(int k=0;k<vt[line[mid][j]].size();++k){
				sid[vt[line[mid][j]][k].stop]=min(sid[vt[line[mid][j]][k].stop]
				,sid[mid]+vt[line[mid][j]][mid].t+vt[line[mid][j]][k].t);
			}
		}
		int mn=INF,li=0;
		for(int j=1;j<=m;++j){
			if(sid[i]<mn){
				mn=sid[i];li=j;
			}
		}
		mid=li;
		p[li]=1;
	}
	return sid[ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		for(int j=1;j<=k;++j){
			int a,t;cin>>a>>t;
			vt[i].push_back({a,t});
			line[a].push_back(i);
		}
	}
	for(int op=1;op<=q;++op){
		int x,y;cin>>x>>y;
		long long ans=w[x]+w[y];
		int u=djstl(x,y);
		cout<<ans+u<<endl;
	}
	return 0;
}
