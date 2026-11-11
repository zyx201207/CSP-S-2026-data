#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,a[789113],ans=0,vis[789113],d,dirmn=0x3f3f3f3f3f3f3f3f,dir,cnt;
vector<ll> vec[789113];
stack<ll> st;
struct node{
    ll x,d;
};
ll bfs(ll u,ll v){
    memset(vis,0,sizeof(vis));
    queue<node> q;
    q.push({u,0});
    while(!q.empty()){
        node now=q.front();
        q.pop();
        if(now.x==v) return now.d;
        for(ll i=0;i<vec[now.x].size();i++){
            if(vis[vec[now.x][i]]==0){
                vis[vec[now.x][i]]=1;
                q.push({vec[now.x][i],now.d+1});
            }
        }
    }
    return -114514;
}
void dfs(ll u,ll v){
    if(u==v){
        vis[v]=0;
        st.push(dir);
        return;
    }
    for(ll i=0;i<vec[u].size();i++){
        if(vis[vec[u][i]]==0){
            vis[vec[u][i]]=1;
            dir++;
            dfs(vis[vec[u][i]],v);
            dir--;
            vis[vec[u][i]]=0;
        }
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        cin>>n>>d;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                if(a[j]-a[i]<=d) vec[i].push_back(j);
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                dfs(i,j);
                while(!st.empty()){
                    if(st.top()==bfs(i,j)) ans++;
                    st.pop();
                }
                if(ans==2) cnt++;
                ans=0;
            }
        }
        cout<<cnt<<"\n";
        cnt=0;
        for(ll i=0;i<n;i++){
            for(ll k=0;k<vec[i].size();k++){
                vec[i].pop_back();
            }
        }
    }
    return 0;
}
