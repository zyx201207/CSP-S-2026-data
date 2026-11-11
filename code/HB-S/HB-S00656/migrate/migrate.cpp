#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define lowbit(op) (op&-op)
inline pii operator + (const pii &x,const pii &y) {return {x.f+y.f,x.s+y.s};}
inline pii operator - (const pii &x,const pii &y) {return {x.f-y.f,x.s-y.s};}
inline int operator ^ (const pii &x,const pii &y) {return x.f*y.s-x.s*y.f;}

const int maxn=2000010;
int n,c,t;
ll d;
ll s[maxn];
ll f[maxn],g[maxn],ans;
namespace solve1112{
    ll k;ll drt;
    void main() {
        drt=s[2]-s[1];
        k=d/drt;
        if(k<=1) {cout << 0 << '\n';return;}
        cout << max(0ll,n+1-2*k) << '\n';
    }
}
const int inf=maxn;
namespace solven2{
    int dis[5010][5010];
    ll cnt[5010][5010],ans;
    void main() {
        ans=0;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j]=inf,cnt[i][j]=0;
        for (int i = 1; i <= n; i++) {
            int pre=i,nxt=i+1;dis[i][i]=0;cnt[i][i]=1;
            ll sum=1;
            for (int j = i+1; j <= n; j++) {
                dis[i][j]=inf;
                while(pre<=n&&s[j]-s[pre]>d) sum-=cnt[i][pre++];
                dis[i][j]=dis[i][pre]+1;
                if(dis[i][j]>n) break;
                while(nxt<pre) sum+=cnt[i][nxt++];
                while(nxt<=n&&dis[i][nxt]+1==dis[i][j]) sum+=cnt[i][nxt++];
                cnt[i][j]=sum;
                if(sum==2) ans++;
            }
        }
        cout << ans << '\n';
    }
}
namespace solvefrac_nV_d{
    int nxt[maxn];
    void init() {
        for (int i = 1; i <= n; i++) nxt[i]=i;
        for (int i = 1, j = 1; i <= n; i++) {while(j<=n&&s[j]-s[i]<=d) ++j;nxt[i]=j-1;}
    }
    ll ans=0;
    void main() {
        init();ans=0;int sum=0;
        for (int i = n; i >= 1; i--) {
            if(i!=n&&nxt[i]==nxt[i+1]&&nxt[i]-2>i+1) {ans+=sum;continue;}
            int l=i,r=i,L,R,cnt[3]={1,3,3},ncnt[3];sum=0;
            while(true) {
                L=r+1,R=nxt[r];
                if(R<L) break;
                if(cnt[0]>2) break;
                if(cnt[0]==cnt[1]&&cnt[0]==1) {
                    int _l=nxt[r-2]+1,_r=nxt[r-1];
                    _l=max(L,_l);_r=min(R,_r);
                    sum+=max(_r-_l+1,0);
                }
                if(cnt[0]==2) {
                    int _l=nxt[r-1]+1,_r=nxt[r];
                    _l=max(L,_l);_r=min(R,_r);
                    sum+=max(_r-_l+1,0);
                }
                ncnt[0]=ncnt[1]=ncnt[2]=0;
                int _R=R,_L=max(L,R-2),_r=r,_l=max(l,r-2);
                for (int i = 0; i+_L<=_R; i++) 
                    for (int j = 0; j+_l<=_r; j++) 
                        if(s[_R-i]-s[_r-j]<=d) ncnt[i]+=cnt[j];
                if(R-L+1<=2) ncnt[2]=3;if(R-L+1<=1) ncnt[1]=3;
                cnt[0]=ncnt[0];cnt[1]=ncnt[1];cnt[2]=ncnt[2];
                l=L,r=R;
            }
            ans+=sum;
        }
        cout << ans << '\n';
    }
}
namespace solve{
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> s[i];
        if(n==1) {cout << 0 << '\n';continue;}
        if(c==11||c==12) solve1112::main();
        else if(n<=5000) solven2::main();
        else solvefrac_nV_d::main();
    }
    return 0;
}

/*
15:37 kancuotile!!!!
15:57 I think I know why it has several tests (cout << 0;)
18:15 expected: 100+100(?)+72+0=272
if T3 solution is totally different from my thought, ******
*/