#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define i128 __int128
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace IO{
    template<typename T>
    inline void read(T &x){
        x=0;bool fl=1;
        char c=gc();
        while(c<'0'||c>'9'){if(c=='-')fl=0;c=gc();}
        while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=gc();
        x=fl?x:-x;
    }
    template<typename T>
    inline void write(T x){
        if(x<0) pc('-'),x=-x;
        if(x>9) write(x/10);
        pc(x%10+'0');
    }
}using namespace IO;
const int N=2e6+5;
int tid,T;
int n;ll d;
ll a[N];
int dp[N],sdp[N],cnt[N],c[N];
inline void solve(){
    read(n),read(d);
    rep(i,1,n) read(a[i]);
    if(tid<=10||tid>12){
        ll ans=0;
        rep(i,1,n){
            rep(i,0,n) cnt[i]=c[i]=0,dp[i]=sdp[i]=1e9;
            dp[i]=0;
            int l=i;
            ++cnt[0];
            rep(j,i+1,n){
                while(a[j]-a[l]>d) cnt[dp[l]]-=c[l],++l;
                if(l==j) break;
                if(cnt[dp[l]]==2) ++ans;
                dp[j]=dp[l]+1,c[j]=cnt[dp[l]],cnt[dp[j]]+=c[j];
            }
            int c=0;
        }
        write(ans),pc('\n');
    }else if(tid<=12){
        rep(i,0,n) cnt[i]=c[i]=0,dp[i]=sdp[i]=1e9;
        dp[1]=0;
        int l=1,pos=n+1;
        ++cnt[0];
        rep(j,2,n){
            while(a[j]-a[l]>d) cnt[dp[l]]-=c[l],++l;
            if(l==j) break;
            if(cnt[dp[l]]==2){pos=j;break;}
            dp[j]=dp[l]+1,c[j]=cnt[dp[l]],cnt[dp[j]]+=c[j];
        }
        write(n-pos+1),pc('\n');
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read(tid),read(T);
    while(T--) solve();
    return 0;
}