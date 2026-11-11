#include<bits/stdc++.h>
using namespace std;
int n,k,ans=INT_MAX;
vector<int>t[100001];
int f[100001],e[1001];
vector<int>v(n+1);
void dddfs(int x){
    for(auto y:t[x]){
        if(!e[y]&&f[y]){
            e[y]=1;
            dddfs(y);
        }
    }
}
void dfs(int x,int o){
    if(x==n+1){
        if(o!=k)return;
        queue<int>q;
        for(int i=1;i<=n;i++)v[i]=e[i]=0;
        int cnt=0;
        for(int i=1;i<=n;i++)if(f[i]){
            q.push(i);
            v[i]=1;
            if(!e[i]){
                e[i]=1;
                cnt++;
                dddfs(i);
            }
        }
        if(cnt>2)return;
        while(q.size()){
            int x=q.front();
            q.pop();
            for(auto y:t[x]){
                if(!v[y]){
                    v[y]=v[x]+1;
                    q.push(y);
                }
            }
        }
        int ma=0;
        for(int i=1;i<=n;i++)ma=max(ma,v[i]);
        ans=min(ans,ma-1);
        return;
    }
    dfs(x+1,o);
    f[x]=1;
    dfs(x+1,o+1);
    f[x]=0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            t[i].clear();
            f[i]=0;
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            t[u].push_back(v);
            t[v].push_back(u);
        }
        dfs(1,0);
        cout<<ans<<'\n';
        ans=INT_MAX;
    }
    return 0;
}
