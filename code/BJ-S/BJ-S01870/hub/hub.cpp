#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define req(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define ll long long
#define ull unsigned ll
using namespace std;
const int N=1e6+5;
const ll INF=(1ll<<60);
ll c,t,n,k,u,v,ans,fa[N],dis[50][50];
bool vis[50][50],qwq[N];
set<pair<ll,ll> > S;
vector<ll> G[N];
ll fr(ll now){
    return fa[now]==now?now:fa[now]=fr(fa[now]);
}
void merge(ll x,ll y){
    ll fx=fr(x),fy=fr(y);
    if(fx!=fy)fa[fx]=fy;
}
bool chk(){
    ll s=0;
    rep(i,1,n)s+=qwq[i];
    if(s!=k)return false;
    rep(i,1,n)fa[i]=i;
    vector<ll> V;V.clear();
    rep(i,1,n)if(qwq[i])V.push_back(i);
    for(auto i:V)for(auto j:V){
        if(S.count(make_pair(i,j))==1){
            merge(i,j);
        }
    }
    set<ll> ss;ss.clear();
    for(auto i:V)ss.insert(fr(i));
    if(ss.size()<=2)return true;
    return false;
}
ll calc(){
    ll ans=0;
    rep(i,1,n)if(!qwq[i]){
        ll minn=INF;
        rep(j,1,n)if(qwq[j]){
            minn=min(minn,dis[i][j]);
        }
        ans=max(ans,minn);
    }
    return ans;
}
void dfs(ll tmp){
    if(tmp==n+1){
        if(chk())ans=min(ans,calc());
        return;
    }
    qwq[tmp]=0;
    dfs(tmp+1);
    qwq[tmp]=1;
    dfs(tmp+1);
}
void dfs2(ll st,ll now){
    for(auto v:G[now]){
        if(!vis[st][v]){
            vis[st][v]=1;
            dis[st][v]=dis[st][now]+1;
            dfs2(st,v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if(c>=13&&c<=14){
        while(t--){
            cin>>n>>k;
            rep(i,1,n-1)cin>>u>>v;
            if(n==k){
                cout<<"0\n";
                continue;
            }
            if(k>=(n-1)/2){
                cout<<"1\n";
                continue;
            }
            ll sum=(n+1)/2-k+2;
            if(sum%4==0){
                cout<<sum/4<<"\n";
            }
            else cout<<sum/4+1<<"\n";
        }
        return 0;
    }
    while(t--){
        cin>>n>>k;
        rep(i,1,n)G[i].clear();
        S.clear();
        rep(i,1,n-1){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
            S.insert(make_pair(u,v));
        }
        rep(i,1,n){
            rep(j,1,n)vis[i][j]=0;
            vis[i][i]=1,dis[i][i]=0,dfs2(i,i);
        }
        ans=INF;
        dfs(1);
        cout<<ans<<"\n";
    }
    return 0;
}