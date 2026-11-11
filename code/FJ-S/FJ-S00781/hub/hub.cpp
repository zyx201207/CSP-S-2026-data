#include<bits/stdc++.h>
using namespace std;
int c,T,n,d;
struct tu{
	int uu,sh;
}a[1000010];
vector<int> g[1000010];
bool cmp(tu x,tu y){
	return x.sh>y.sh;
}
bool vis[1000010],vv[1000010];
int ans[1000010],ma;
map<int,int>t;
queue<int> q;
void bfs(){
	while(q.size()){
		int u=q.front();
		q.pop();
		vv[u]=1;
		for(auto j:g[u]){
			if(vv[j]){
				continue;
			}
			ans[j]=ans[u]+1;
			ma=max(ans[j],ma);
			q.push(j);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			a[u].uu=u;
			a[v].uu=v;
			a[u].sh++;
			a[v].sh++;
		}
		sort(a+1,a+n+1,cmp);
		int cnt=0;
		for(int i=1;cnt<=d&&cnt<2;i++){
			bool f=1;
			for(auto v:g[a[i].uu]){
				if(vis[v]==1){
					f=0;
					break;
				}
			}
			if(f){
				cnt++;
//				cout<<a[i].uu<<" ";
				vis[a[i].uu]=1;
				t[a[i].uu]=1;
				a[i].sh--;
				for(auto j:g[a[i].uu]){
					vis[j]=1;
					a[j].sh--;
				}
				q.push(a[i].uu);
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;cnt<d;i++){
			if(vis[a[i].uu]&&t[a[i].uu]==0){
				cnt++;
				t[a[i].uu]=1;
				a[i].sh--;
				q.push(a[i].uu);
				for(auto j:g[a[i].uu]){
					vis[a[j].uu]=1;
					a[j].sh--;
				}
			}
		}
		bfs();
		cout<<ma<<endl;
		for(auto it:t){
			cout<<it.first<<" ";
		}
		cout<<endl;
		t.clear();
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		fill(vis,vis+n+1,0);
		fill(vv,vv+n+1,0);
		for(int i=1;i<=n;i++){
			a[i].sh=a[i].uu=0;
		}
		ma=0;
	}
	return 0;
} 
