#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int hao,T,n;
long long d,x[MAXN],ans,dp[MAXN],dp2[MAXN],sdp[MAXN],sdp2[MAXN];
inline long long read(){
    long long x=0;
    int f=1;
    char c;
    c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
inline void write(long long x){
    if(x<10){
        putchar(x+'0');
        return ;
    }
    write(x/10);
    putchar(x%10+'0');
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    hao=read();T=read();
    while(T--){
        ans=0;
        n=read();d=read();
        for(int i=1;i<=n;++i) x[i]=read();
        x[n+1]=4e18;
        x[0]=-(4e18);
        for(int i=1;i<=n;++i){
            if(i>1){
                if(x[i-1]+d>=x[i]&&x[i-1]+d<x[i+1]&&x[i]-d>x[i-2]) dp[i]=dp[i-1]+1;
                else dp[i]=1;
            }
            else dp[i]=1;
        }
        for(int i=n;i>=1;i--){
            if(i<n){
                if(x[i+1]-d<=x[i]&&x[i+1]-d>x[i-1]&&x[i]+d<x[i+2]) dp2[i]=dp2[i+1]+1;
                else dp2[i]=1;
            }
            else dp2[i]=1;
            sdp2[i]=sdp2[i+1]+dp2[i];
        }
        for(int i=1;i<=n-3;++i){
            int pos=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
            if(pos<i+2) continue;
            int to=upper_bound(x+1,x+n+1,x[pos-1]+d)-x-1;
            int lim=upper_bound(x+1,x+n+1,x[pos-2]+d)-x-1;
            if(lim<to){
                ans+=dp[i]*(sdp2[lim+1]-sdp2[to+1]);
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}