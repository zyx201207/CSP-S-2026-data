#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define w(x) cerr<<#x<<':'<<x<<endl
#define dbg cerr<<"\n----------------\n"
#define fi first
#define sc second
#define pii pair<int,int>
#define gc getchar_unlocked
#define pc putchar_unlocked
namespace IO{
    template<typename T>
    inline void read(T &x){
        x=0;char c=gc();bool fl=1;
        while(c<'0' || c>'9'){if(c=='-') fl=0;c=gc();}
        while(c>='0' && c<='9') x=(x<<1)+(x<<3)+c-48,c=gc();
        x=fl?x:-x;
    }
    template<typename T>
    void write(T x){
        if(x<0) x=-x,pc('-');
        if(x>9) write(x/10);
        pc('0'+x%10);
    }
    inline void read(char &c){while(isspace(c=gc()));}
    inline void write(char &c){pc(c);}
}
using namespace IO;
const int inf=3e18;
const int mod=998244353;
const int N=2e6+5;
int T,n,m,x,c,y,d,z,L,cnt,now,sum,ans,len;
int pos[N],l[N],r[N];
pii dp[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read(c),read(T);
    if(c>=1 && c<=10){
        while(T--){
            read(n),read(d);
            ans=0;
            for(int i=1;i<=n;i++) read(pos[i]);
            for(int i=1;i<=n;i++){
                l[i]=lower_bound(pos+1,pos+1+n,pos[i]-d)-pos;
                r[i]=upper_bound(pos+1,pos+1+n,pos[i]+d)-pos-1;
            }
            for(int i=1;i<=n;i++){
                dp[i]={0,0};
                for(int j=i+1;j<=n;j++){
                    int lst=max(l[j],i);
                    if(lst==j) break;
                    dp[j].fi=dp[lst].fi+1;
                    dp[j].sc=dp[lst].sc;
                    if(lst+1<j && dp[lst+1].fi==dp[lst].fi) dp[j].sc++;
                    if(lst+2<j && dp[lst+2].fi==dp[lst].fi) dp[j].sc++;
                    if(dp[j].sc==1) ans++;
                }
            }
            write(ans),pc('\n');
        }
        return 0;
    }
    else if(c>=11 && c<=12){
        while(T--){
            read(n),read(d);
            for(int i=1;i<=n;i++) read(pos[i]);
            x=pos[2]-pos[1];
            if(d/x<=1) write(0);
            else write(max(n-(d/x)*2+1,0ll));
            pc('\n');
        }
        return 0;
    }else{
        while(T--){
            read(n),read(d);
            ans=0;
            for(int i=1;i<=n;i++) read(pos[i]);
            for(int i=1;i<=n;i++){
                l[i]=lower_bound(pos+1,pos+1+n,pos[i]-d)-pos;
                r[i]=upper_bound(pos+1,pos+1+n,pos[i]+d)-pos-1;
            }
            for(int i=1;i<=n;i++){
                now=r[i];
                if(now==i) continue;
                int fl=0;
                while(now<=n){
                    if(r[now]==now) break;
                    if(fl==2){
                        if(r[now-1]==r[now]) break;
                        ans+=r[now]-r[now-1];
                    }else if(fl==1){
                        if(r[now-1]==r[now]) break;
                        if(r[now-1]<r[now]-1) fl=0;
                    }else if(fl==0){
                        if(now>1 && r[now-1]>now){
                            int R=r[now-1],L=r[now-2];
                            ans+=(R-max(L,now));
                            if(L==r[now]) break;
                            if(R==r[now]-1) fl=1;
                            if(R==r[now]) fl=2;
                        }
                    }
                    now=r[now];
                }
            }
            write(ans),pc('\n');
        }
    }
    cerr<<endl<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
