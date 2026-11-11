#include<bits/stdc++.h>
#define wef(i,l,r) for(int i=l;i<=r;i++)
#define few(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define endl cout<<"\n"
using namespace std;
using ll=long long;
const int N=15;
vector<int> g[N];
int v[N],d[N],vv[N];
void dfs(int x,int Fa){
	for(int y:g[x]){
		if(vv[y]||!v[y]) continue;
		vv[y]=1;
		dfs(y,x);
	}
}
int n,k;
inline void bfs(){
	queue<int> q;
	wef(i,1,n) if(v[i]) q.push(i);
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int y:g[x]){
			if(v[y]) continue;
			v[y]=1;
			d[y]=d[x]+1;
			q.push(y);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int CCC,T;
	cin>>CCC>>T;
	if(CCC<=3){
		while(T--){
			cin>>n>>k;
			wef(i,1,n) g[i].clear();
			wef(i,1,n-1){
				int x,y;
				cin>>x>>y;
				g[x].push_back(y);
				g[y].push_back(x);
			}
			int res=0x3f3f3f3f;
			wef(s,1,(1<<n)-1){
				if(__builtin_popcount(s)!=k) continue;
				memset(d,0,sizeof d);
				memset(v,0,sizeof v);
				memset(vv,0,sizeof vv);
				wef(i,0,n-1) v[i+1]=((s>>i)&1);
//				wef(i,1,n) cout<<v[i]<<" ";
//				endl;
				int cnt=0;
				wef(i,1,n) if(v[i]&&!vv[i]) cnt++,dfs(i,0);
				if(cnt>2){
//					cout<<cnt<<"\n";
					continue;
				}
				bfs();
				int maxn=0;
				wef(i,1,n){
					maxn=max(maxn,d[i]); 
				}
//				wef(i,1,n) cout<<d[i]<<" ";
//				cout<<cnt<<" "; 
//				cout<<maxn<<" ";
//				endl;
				res=min(res,maxn);
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
