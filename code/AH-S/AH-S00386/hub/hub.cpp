#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long x=0;
    int f=1;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-48;
        c=getchar();
    }
    return x*f;
}
int c,T,n,k,p[1005],f[1005];
vector<int>g[1005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read();
    T=read();
    while(T--){
        n=read();
        k=read();
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1,u,v;i<n;i++){
            u=read();
            v=read();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=1;i<=n;i++)p[i]=0;
        for(int i=n-k+1;i<=n;i++)p[i]=1;
        int ans=1e9;
        do{
            queue<int>q;
            while(q.size())q.pop();
            int maxn=0,cnt=0;
            for(int i=1;i<=n;i++){
                if(p[i]){
                    for(int j=0;j<g[i].size();j++){
                        if(p[g[i][j]]){
                            cnt++;
                        }
                    }
                }
            }
            cnt/=2;
            if(k-cnt>2)continue;
            for(int i=1;i<=n;i++)f[i]=-1;
            for(int i=1;i<=n;i++){
                if(p[i]){
                    q.push(i);
                    f[i]=0;
                }
            }
            while(q.size()){
                int u=q.front();
                q.pop();
                for(int i=0;i<g[u].size();i++){
                    if(f[g[u][i]]==-1){
                        f[g[u][i]]=f[u]+1;
                        maxn=max(maxn,f[g[u][i]]);
                        q.push(g[u][i]);
                    }
                }
            }
            ans=min(ans,maxn);
        }while(next_permutation(p+1,p+n+1));
        printf("%d\n",ans);
    }
    return 0;
}
