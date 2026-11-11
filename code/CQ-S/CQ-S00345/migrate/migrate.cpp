#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>G[50005];
int x[50005];
int n,d;
int bfs(int st,int ed){
    queue<pair<int,int>>q;
    q.push({st,0});
    int res=0,ans=0;
    while(q.size()){
        int x=q.front().first,cnt=q.front().second;
        q.pop();
        // cerr<<x<<" "<<cnt<<"\n";
        if(res&&ed-x>d*(res-cnt))continue;
        if(x>ed)continue;
        if(x!=ed&&res&&cnt==res)continue;
        if(res&&cnt>res)break;
        if(x==ed&&(res==0||cnt==res)){
            ans++,res=cnt;
            continue;
        }
        for(auto y:G[x])q.push({y,cnt+1});
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(x[j]-x[i]<=d)G[i].push_back(j);
        int ans=0;
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(bfs(i,j)==2)ans++;
        cout<<ans<<"\n";
    }
    return 0;
}