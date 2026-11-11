
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
struct edge{
    int v,w;
};
vector<int> e[N];
ll a[N];
int n,d[N],cnt[N];
bool vis[N];
ll bfs(int s){
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    memset(d,0x3f,sizeof(d));
    queue<edge> q;
    q.push({s,0});
    d[s]=0;
    ll res=0;
    while(!q.empty()){
        int u=q.front().v;
        int dis=q.front().w;
        q.pop();
        if(d[u]==dis && vis[u]) cnt[u]++;
        if(vis[u]) continue;
        vis[u]=1;
        for(int v:e[u]){
            d[v]=min(d[v],dis+1);
            q.push({v,dis+1});
        }
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]==1) res++;
    }
    return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
        ll d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            e[i].clear();
        }
        if(c<=10){
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    if(i!=j){
                        if(abs(a[i]-a[j])<=d){
                            e[i].push_back(j);
                        }
                    }
                }
            }
            ll ans=0;
            for(int i=1;i<=n;i++){
                ans+=bfs(i);
            }
            cout<<ans<<'\n';
            continue;
        }
        cout<<0<<'\n';
	}
	return 0;
}
