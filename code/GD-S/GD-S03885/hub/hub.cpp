#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int c,Q;
int n,cut,k;
vector<int> to[1000007];
int du[1000007],fa[1000007];
int cnt[1000007],dep[1000007];
int v[1000007],ccnt[1000007];
int sz[1000007],vis[1000007];
void dfs(int x){
	sz[x]=1;
	for(auto nx:to[x]){
		if(nx==fa[x]) continue;
		fa[nx]=x;
		dfs(nx);
		sz[x]+=sz[nx];
	}
}
void vfs(int x){
	v[x]=1;
	for(auto nx:to[x]){
		if(nx==fa[x]) continue;
		vfs(nx);
	}
}
queue<int> q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>Q;
	for(int qqq=1;qqq<=Q;++qqq){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			to[i].clear(); 
			fa[i]=du[i]=sz[i]=0;
		}
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			to[x].push_back(y);
			to[y].push_back(x);
		}
		if(k==n){
			cout<<"0\n";
			continue;
		}
		if(c==13||c==14){
			int m=(n-1)/2;
			for(int i=0;i<=m/2;++i){
				if(m-4*i<=k){
					cout<<i+1<<"\n";
					break;
				}
			}
			continue;
		}
		dfs(1);
		int ans=n-1;
		for(cut=2;cut<=n;++cut){
			for(int i=1;i<=n;++i) cnt[i]=ccnt[i]=v[i]=0,du[i]=0,dep[i]=0,vis[i]=0;
			for(int i=1;i<=n;++i){
				du[i]=to[i].size();
				for(auto ni:to[i]){
					if((i==cut&&ni==fa[cut])||(i==fa[cut]&&ni==cut)){
						du[i]--;
					}
				}
			}
			vfs(cut);
			while(!q.empty()) q.pop();
			for(int i=1;i<=n;++i){
				if(du[i]==1){
					q.push(i);
					dep[i]=1;
				}
			}
			while(!q.empty()){
				int x=q.front();
				q.pop();
				vis[x]=1;
				if(!v[x]) cnt[dep[x]]++;
				else ccnt[dep[x]]++;
				for(auto nx:to[x]){
					if(vis[nx]||(x==cut&&nx==fa[cut])||(x==fa[cut]&&nx==cut)) continue;
					dep[nx]=max(dep[nx],dep[x]+1),du[nx]--;
					if(du[nx]<=1) q.push(nx);
				}
			}
			int now=0,nnow=0;
			for(int i=1;i<=n;++i){
				now+=cnt[i],nnow+=ccnt[i];
				if(nnow==sz[cut]){
					if(n-sz[cut]-now+1<=k){
						ans=min(ans,i);
						break;
					}
				}else if(now==n-sz[cut]){
					if(sz[cut]-nnow+1<=k){
						ans=min(ans,i);
						break;
					}
				}else{
					if(n-now-nnow<=k){
						ans=min(ans,i);
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0; 
}
