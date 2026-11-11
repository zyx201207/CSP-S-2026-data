#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
namespace Manaka_Ao{
    #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
    char buf[1<<20],*p1=buf,*p2=buf;
    inline int read(){
        int ans=0,w=1;
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
    const int N=505,M=500005;
    int C,n,m,d,Q;
    int w[M];
    struct node{
        ll w;
        int id;
    };
    vector<node>vec[M];
    ll f[N][N];
    int main(){
        C=read(),n=read(),m=read(),d=read(),Q=read();
        for(int i=1;i<=m;i++)w[i]=read();
        for(int i=1;i<=n;i++){
            int k=read();
            for(int j=1;j<=k;j++){
                int x=read(),t=read();
                vec[x].push_back({t,i});
            }
        }
        memset(f,0x3f,sizeof f);
        for(int i=1;i<=m;i++){
            for(node p:vec[i])for(node q:vec[i]){
                f[p.id][q.id]=min(f[p.id][q.id],p.w+q.w);
            }
        }
        for(int i=1;i<=n;i++)f[i][i]=0;
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
        while(Q--){
            int x=read(),y=read();
            ll ans=1e18;
            for(node p:vec[x])for(node q:vec[y]){
                ans=min(ans,f[p.id][q.id]+w[x]+w[y]+p.w+q.w);
            }
            cout<<ans<<'\n';
        }
        return 0;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    Manaka_Ao::main();
    return 0;
}
/*
g++ -std=c++14 subway.cpp -o subway -lm -O2 -static -Wl,-stack=2000000000
.\subway

*/
//33MB