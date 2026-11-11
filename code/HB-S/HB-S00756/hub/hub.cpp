#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int INF=1e9+10;
int c,t,n,k,ans;
int vis[N],a[N],fa[N];
vector<int> g[N];
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-f;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(),t=read();
    while(t--){
        n=read(),k=read();
        for(int i=1;i<=n;++i){
            while(g[i].size()) g[i].pop_back(); 
        }
        for(int i=1;i<n;++i){
            int u=read(),v=read();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(k==n) cout<<0<<'\n';
        else if(k>=n/2+1) cout<<1<<'\n';
        else{
            int m=n/2;
            cout<<m/k+1;
        } 
    }
    return 0;
}