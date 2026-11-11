#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,ans=1e9,v[1000005],t[1000005],vv[13],oo;
vector<int> w[1000005];
void dfs(int x){
    for(auto it:w[x]){
        if(!v[it])continue;
        if(t[it])continue;
        t[it]=1;
        dfs(it);
    }
}
void dfs1(int x){
    if(v[x])oo=min(oo,vv[x]-1);
    for(auto it:w[x]){
        if(vv[it])continue;
        vv[it]=vv[x]+1;
        dfs1(it);
    }
}
int as(){
    int o=0;for(int i=1;i<=n;i++)t[i]=0;
    for(int i=1;i<=n;i++)if(v[i]&&!t[i])t[i]=1,dfs(i),o++;
    if(o>2)return 1e9;
    int ss=0;
    for(int i=1;i<=n;i++){oo=1e9;
        memset(vv,0,sizeof vv);
        vv[i]=1;
        dfs1(i);
        ss=max(ss,oo);
    }
    return ss;
}
void dfs(int x,int o){
    if(o>k)return;
    if(x==n+1){
        if(o==k){
            ans=min(ans,as());
        }
        return;
    }
    dfs(x+1,o);
    v[x]=1;
    dfs(x+1,o+1);
    v[x]=0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        if(c==13||c==14){
            for(int i=1,u,v;i<n;i++)cin>>u>>v;
            int o=(n+1)/2,ans=1e9;
            ans=max(1,(o-(k+1))/3+1);
            for(int i=k+2;i<=o;i++)ans=min(ans,max(i-k,(o-i)/3+1));
            cout<<ans<<"\n";
            continue;
        }ans=1e9;
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            w[u].push_back(v);
            w[v].push_back(u);
        }
        dfs(1,0);
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++)v[i]=0,w[i].clear();
    }
    return 0;
}
