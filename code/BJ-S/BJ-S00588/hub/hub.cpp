#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int c,t,n,k,ans;
bool is[maxn];
vector<int>adj[maxn];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
bool con(int x){
    int sum=0;
    for(int i=1;i<=n;i++)is[i]=false;
    for(int i=1;i<=n;i++){
        if(1&(x>>i-1)){
            bool flag=false;
            is[i]=true;
            for(int v:adj[i])
                if(is[v])flag=true;
            if(!flag)sum++;
        }
        if(sum>2)return false;
    }
    return true;
}
int bfs(int s,int tmp[],int tot){
    queue<pair<int,int>>q;
    q.push({s,0});
    while(!q.empty()){
        int t=q.front().first,step=q.front().second;
        q.pop();
        for(int i=1;i<=tot;i++)
            if(t==tmp[i])return step;
        for(int v:adj[t]){
            q.push({v,step+1});
        }
    }
}
int solve(int x){
    int tmp[maxn],ttt=0,ans=0;
    for(int i=1;i<=n;i++)
        if(1&(x>>i-1))tmp[++ttt]=i;
    for(int i=1;i<=n;i++){
        ans=max(bfs(i,tmp,ttt),ans);
    }
    return ans;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    c=read(),t=read();
    while(t--){
        for(int i=1;i<=n;i++)
            adj[i].clear();
        ans=INT_MAX;
        n=read(),k=read();
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<(1<<n);i++){
            int num=0;
            for(int j=1;j<=n;j++)
                if(1&(n>>(j-1)))num++;
            if(num!=k)continue;
            if(!con(i))continue;
            ans=min(ans,solve(i));
        }
        cout<<ans;
    }
    return 0;
}
