#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int cid,T,n,d,x[N],lst[N],nxt[N];

namespace solve1{
    const int M=5005;
    signed f[M][M],g[M][M];
    void solve(){
        int mm=1,ans=0;
        for(int i=2;i<=n;++i){
            if(lst[i]==i){mm=i;continue;}
            for(int j=mm;j<lst[i];++j){
                f[j][i]=f[j][lst[i]]+1;
                if(lst[i]==i-1||f[j][lst[i]]!=f[j][lst[i]+1]){
                    g[j][i]=g[j][lst[i]];
                }
                else if(lst[i]==i-2||f[j][lst[i]+1]!=f[j][lst[i]+2]){
                    g[j][i]=min(3,g[j][lst[i]]+g[j][lst[i]+1]);
                }
                else g[j][i]=3;
                if(g[j][i]==2)++ans;
            }
            for(int j=lst[i];j<i;++j){
                f[j][i]=1;g[j][i]=1;
            }
        }
        print(ans);putchar('\n');
    }
}

namespace solve2{
    void solve(){
        int gd=x[2]-x[1];
        int g=d/gd;
        if(g<=1)print(0),putchar('\n');
        else{
            int ans=n-g-(g-1);
            print(max(ans,0ll));putchar('\n');
        }
    }
}

// namespace solve3{
//     int work(int x){
//         if(nxt[x]==x)return 0;
//         int ans=0,t1,t2,t3,l=x,s[3];
//         t1=nxt[x];t2=t3=x;
//         while(l<n){
//             if(nxt[l]==l)return ans;
//             s[0]=s[1]=s[2]=1;
//             for(int i=0;i<3;++i)if(nxt[t2]>=nxt[t1])
//         }
//     }
//     void solve(){}
// }

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cid=read();T=read();
    while(T--){
        n=read();d=read();
        for(int i=1;i<=n;++i)x[i]=read();
        for(int i=1,j=1;i<=n;++i){
            while(x[i]-x[j]>d)++j;
            lst[i]=j;
        }
        for(int i=n,j=n;i>=1;--i){
            while(x[j]-x[i]>d)--j;
            nxt[i]=j;
        }
        if(cid<=10)solve1::solve();
        else if(11<=cid&&cid<=12)solve2::solve();
    }
    return 0;
}