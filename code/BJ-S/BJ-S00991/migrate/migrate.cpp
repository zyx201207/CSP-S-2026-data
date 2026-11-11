#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,d,x[N],t,c;
int bfs(int l){
    queue<pair<int,int>>q;q.push({l,0});
    vector<int>dis(n+1,1e9),cnt(n+1,0);dis[l]=0;
    while(!q.empty()){
        auto[u,ds]=q.front();q.pop();
        if(ds>dis[u]) continue;
        for(int i=u+1;i<=n&&x[i]-x[u]<=d;i++) {
            q.push({i,dis[u]+1});
            if(dis[i]==dis[u]+1) cnt[i]++;
            else if(dis[i]>dis[u]+1) dis[i]=dis[u]+1,cnt[i]++;
        }
    }int res=0;
    for(int i=l;i<=n;i++)
        if(cnt[i]==2)
            res++;
    return res;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;int ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++) ans+=bfs(i);
        cout<<ans<<'\n';
    }
    return 0;
}

