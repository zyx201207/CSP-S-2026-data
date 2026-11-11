#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,w[1000005],k[1000005],a[1005][1005],t[1005][1005],id2[1005][1005],memo[505][505],st,ed,ans=1e9;
vector<int> id[1000005];
bool vis[100005];
void dfs(int x,int sum){
    if(x==ed){
        ans=min(ans,sum+w[ed]);
        return;
    }
    if(memo[st][x]>sum) memo[st][x]=sum;
    else return;
    for(auto now:id[x]){
        for(int i=1;i<=k[now];i++){
            if(!vis[a[now][i]]){
                vis[a[now][i]]=1;
                dfs(a[now][i],sum+t[now][id2[x][now]]+t[now][id2[a[now][i]][now]]);
                vis[a[now][i]]=0;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            id[a[i][j]].push_back(i);
            id2[a[i][j]][i]=j;
        }
    }
    while(q--){
        ans=1e9;
        fill(vis+1,vis+m+1,0);
        memset(memo,0x3f,sizeof(memo));
        cin>>st>>ed;
        vis[st]=1;
        dfs(st,w[st]);
        cout<<ans<<"\n";
    }
    return 0;
}

