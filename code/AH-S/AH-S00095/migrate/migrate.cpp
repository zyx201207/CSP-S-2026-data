#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
using ll=__int128;
ll read(){
    ll f=1,x=0;
    char cc=getchar();
    while(!isdigit(cc)){
        if(cc=='-')f=1-f;
        cc=getchar();
    }
    do{
        x=(x<<1)+(x<<3)+(cc^48);
        cc=getchar();
    }while(isdigit(cc));
    return(f?x:-x);
}
ll x[2000005];
int n;
ll d;
void solve(){
    n=read();
    d=read();
    ll sum=0;
    ll res=0;
    for(int i=1;i<=n;++i)x[i]=read();
    for(int i=1;i<=n;++i){
        vector<ll>dst(n+5,0x3f3f3f3f3f3f3f3f);
        vector<ll>dst2(n+5,0x3f3f3f3f3f3f3f3f);
        vector<ll>dst3(n+5,0x3f3f3f3f3f3f3f3f);
        dst[i]=0;
        priority_queue<array<ll,2>,vector<array<ll,2>>,less<array<ll,2>>>q;
        q.push({0,i});
        while(!q.empty()){
            auto[Dst,u]=q.top();
            q.pop();
            if(Dst!=dst[u])continue;
            for(int v=u+1;v<=n;++v){
                int w=x[v]-x[u];
                if(w>d)break;
                if(dst[v]>dst[u]+w){
                    dst[v]=dst[u]+w;
                    q.push({dst[v],v});
                }else if(dst2[v]>dst[u]+w){
                    dst2[v]=dst[u]+w;
                }else if(dst3[v]>dst[u]+w){
                    dst3[v]=dst[u]+w;
                }
            }
        }
        fo(j,i+1,n){
            if(dst[j]==dst2[j]&&dst2[j]!=dst3[j])++res;
        }
    }
    printf("%d\n",res);
    //sum+=x[i];
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=read(),T=read();
    do{
        solve();
    }while(--T);
    return 0;
}
