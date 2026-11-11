#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,qq,ans,w[5010],k[510],b[5010],t[5010][510],v2[5010][1010],cnt[5010];
vector<int>v[510];
queue<pair<int,int> >q;
int bfs(int x,int y){
    memset(b,0,sizeof b);
    for(int i=1;i<=cnt[x];i++){
        q.push({v2[x][i],t[x][v2[x][i]]});
    }
    b[x]=1;
    int ans=1e18;
    while(q.size()){
        auto op=q.front();
        q.pop();
        int xl=op.first,tt=op.second;
        for(int i=0;i<v[xl].size();i++){
            int p=v[xl][i];
            if(p==y){
                ans=min(tt+t[y][xl],ans);
                continue;
            }
            if(b[p]||cnt[p]==1)continue;
            b[v[xl][i]]=1;
            for(int j=1;j<=cnt[p];j++){
                if(xl==v2[p][j])continue;
                q.push({v2[p][j],tt+t[p][v2[p][j]]+t[p][xl]});
            }
        }
    }
    return ans;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            v[i].push_back(x);
            v2[x][++cnt[x]]=i;
            t[x][i]=y;
        }
    }
    while(qq--){
        int x,y;
        while(q.size())q.pop();
        cin>>x>>y;
        cout<<w[x]+w[y]+bfs(x,y)<<"\n";
    }
    return 0;
}
