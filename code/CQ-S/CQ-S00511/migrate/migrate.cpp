#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
namespace Manaka_Ao{
    #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
    char buf[1<<20],*p1=buf,*p2=buf;
    inline ll read(){
        ll ans=0,w=1;
        char ch=getchar();
        while(ch<48||ch>57){
            if(ch=='-')w=-1;
            ch=getchar();
        }
        while(ch>=48&&ch<=57){
            ans=(ans<<1)+(ans<<3)+ch-48;
            ch=getchar();
        }
        return w*ans;
    }
    const int N=2000005;
    int C,T;
    int n;
    ll D;
    ll a[N];
    int nxt[N];
    vector<int>e[N];
    int c[N];
    ll f[N][2];
    ll ans;
    bool is[N];
    void dfs(int x,int fa){
        for(int v:e[x]){
            dfs(v,x);
            if(c[v]==3||is[v])continue;
            if(c[v]==2)f[x][1]+=f[v][0];
            if(c[v]==1)f[x][0]+=f[v][0],f[x][1]+=f[v][1];
        }
        ++f[x][0];
        if(nxt[x]!=x&&nxt[nxt[x]]!=nxt[x]&&nxt[nxt[nxt[x]]]!=nxt[nxt[x]]&&c[x]!=3){//可能产生贡献
            if(c[x]==1){
                int p=nxt[x],q=nxt[p],v=nxt[q];
                // cerr<<x<<' '<<p<<' '<<q<<' '<<v<<"\n";
                int low=q;
                if(p!=x+1&&nxt[p-1]!=q)low=nxt[nxt[p-1]];//>low
                // cerr<<low<<'\n';
                //前面有 1 个
                ans+=f[x][1]*(v-max(nxt[q-1],low));
                //前面有 0 个
                if(q>p+1)ans+=f[x][0]*(nxt[q-1]-max(nxt[q-2],low));
            }else{
                int p=nxt[x],q=nxt[p],v=nxt[q];
                ans+=f[x][0]*(v-nxt[q-1]);
            }
        }
        //只有三元
        if(nxt[x]!=x&&nxt[nxt[x]]!=nxt[x]){
            if(nxt[x]!=x+1)ans+=(nxt[nxt[x]-1]-nxt[nxt[x]-2]);
        }
        // cerr<<"*** "<<x<<' '<<f[x][0]<<' '<<f[x][1]<<' '<<ans<<"\n";
    }
    int main(){
        C=read(),T=read();
        while(T--){
            n=read(),D=read();
            for(int i=1;i<=n;i++)a[i]=read();
            for(int i=n,top=n;i;i--){
                while(top>i&&a[top]-a[i]>D)--top;
                nxt[i]=top;
                // cerr<<i<<' '<<nxt[i]<<'\n';
            }
            for(int i=1;i<=n;i++)if(nxt[i]!=i)e[nxt[i]].push_back(i);
            for(int i=1;i<=n;i++){
                if(nxt[i]!=i&&nxt[nxt[i]]!=nxt[i]){//前面有 3 种情况
                    if(nxt[nxt[i]-1]!=nxt[nxt[i]])c[i]=1;
                    else if(nxt[nxt[i]-2]!=nxt[nxt[i]])c[i]=2;
                    else c[i]=3;//就不行了
                }
                if(nxt[nxt[i]-1]!=nxt[nxt[i]]&&nxt[nxt[nxt[i]-1]]==nxt[nxt[nxt[i]]])is[i]=1;
                // cerr<<"c: "<<c[i]<<' '<<is[i]<<'\n';
            }
            for(int i=n;i;i--){
                if(nxt[i]==i)dfs(i,0);
            }
            cout<<ans<<'\n';
            ans=0;
            for(int i=0;i<=n;i++){
                a[i]=nxt[i]=c[i]=f[i][0]=f[i][1]=is[i]=0;
                e[i].clear();
            }
        }
        return 0;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    // freopen("migrate.err","w",stderr);
    Manaka_Ao::main();
    return 0;
}
/*
g++ -std=c++14 migrate.cpp -o migrate -lm -O2 -static -Wl,-stack=2000000000
.\migrate

*/
/*
至少走两步，所以不用特判只走一步的情况
*/