#include<bits/stdc++.h>
#define OpenFile(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define CloseFile fclose(stdin),fclose(stdout)
#define getchar getchar_unlocked
#define rep(x,y,z) for(int x=(y);x<=(z);++x)
#define per(x,y,z) for(int x=(y);x>=(z);--x)
#define int long long
#define N 500505
using namespace std;
int get(int ans=0,int x=1){
    char ch=getchar();
    while(ch<48||ch>57){if(ch=='-')x=-1;ch=getchar();}
    while(ch>=48&&ch<=57)ans=(ans<<1)+(ans<<3)+ch-48,ch=getchar();
    return ans*x;
}int c,n,m,d,q,w[N],k,f[505][505];
vector<pair<int,int>>ng[N];
void Floyd(){rep(k,1,n)rep(i,1,n)rep(j,1,n)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);}
signed main(){
    OpenFile(subway);
    memset(f,0x3f,sizeof(f));
    c=get(),n=get(),m=get(),d=get(),q=get();
    rep(i,1,m)w[i]=get();
    rep(i,1,n){
        k=get();
        rep(j,1,k){
            int u=get(),v=get();
            ng[m+i].emplace_back(u,v);
            ng[u].emplace_back(m+i,v);
        }
    }rep(i,1,n)f[i][i]=0;
    rep(u,1,m){
        k=ng[u].size();
        rep(i,0,k-1)rep(j,0,k-1){
            auto&s=ng[u][i],t=ng[u][j];
            f[t.first-m][s.first-m]=f[s.first-m][t.first-m]=min(f[s.first-m][t.first-m],s.second+t.second);
        }
    }Floyd();
    rep(_,1,q){
        int s=get(),t=get(),ans=LONG_LONG_MAX;
        for(auto&u:ng[s])for(auto&v:ng[t])ans=min(ans,f[u.first-m][v.first-m]+u.second+v.second);
        printf("%lld\n",ans+w[s]+w[t]);
    }CloseFile;
    return 0;
}
