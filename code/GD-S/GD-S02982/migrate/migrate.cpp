#include <bits/stdc++.h>
#define For(e,e1,e2) for(int e=(e1);e<=(e2);e++)
#define For_(e,e1,e2) for(int e=(e1);e<(e2);e++)
#define Rof(e,e1,e2) for(int e=(e2);e>=(e1);e--)
#define Rof_(e,e1,e2) for(int e=(e2);e>(e1);e--)
#define LL long long
#define ULL unsigned long long
#define DB double
#define cint const int
#define cLL const long long
#define ft first
#define sc second
#define vct vector
#define pb push_back
#define all(ev) ev.begin(),ev.end()
#define sz(ev) ((int)ev.size())
#define exc(ev) if(ev) continue
#define stop(ev) if(ev) break
#define ret(ev) if(ev) return 
#define x0 __xx00__
#define x1 __xx11__
#define y0 __yy00__
#define y1 __yy11__
using namespace std;

void main_init()
{

}
cint N=2.01e6;
int n;
LL d0,a[N];
int nxt[N],pre[N];
int pc[N],nc[N];
void main_solve()
{
    scanf("%d%lld",&n,&d0);
    For(i,1,n) scanf("%lld",&a[i]);
    for(int l=n,r=n;l>=1;l--)
    {
        while(a[r]-a[l]>d0) r--;
        nxt[l]=r;
    }
    for(int r=1,l=1;r<=n;r++)
    {
        while(a[r]-a[l]>d0) l++;
        pre[r]=l;
    }
    // For(i,1,n) printf("%d ",nxt[i]); printf("\n");
    // For(i,1,n) printf("%d ",pre[i]); printf("\n");
    LL ans=0ll;
    /* for(int L=1,R;L<=n;L=R+1)
    {
        R=L; while(R<n&&nxt[R]!=R) R++;
        For(i,L,R) For(j,i+1,R)
        {
            vct <int> h1,h2;
            for(int k=i;k<j;k=nxt[k]) h1.pb(k); h1.pb(j);
            for(int k=j;k>i;k=pre[k]) h2.pb(k); h2.pb(i);
            reverse(all(h2));
            int len=sz(h1);
            bool ck=true; int ck2=0;
            For_(k,0,len) ck&=(h1[k]-h2[k]<=1),ck2+=(h1[k]-h2[k]>0);
            if(ck&&ck2==1) ans++;
        }
    } */
    for(int i=1,j=0;i<=n;i++)
    {
        while(j<n&&nxt[j+1]<=i) j++;
        pc[i]=1+(((pre[i]<i)&&nxt[pre[i]]==i)?(pc[pre[i]]+(j-pre[i])):0);
    }
    for(int i=n,j=n+1;i>=1;i--)
    {
        while(j>1&&pre[j-1]>=i) j--;
        nc[i]=1+(((nxt[i]>i)&&pre[nxt[i]]==i)?(nc[nxt[i]]+(nxt[i]-j)):0);
    }
    For(i,1,n-1) if(nxt[i]>i+1&&pre[i+1]<i&&nxt[pre[i+1]]==i+1&&pre[nxt[i]]==i)
    {
        int c1=((nxt[i]==nxt[i+1])?nc[nxt[i]]:1);
        int c2=((pre[i+1]==pre[i])?pc[pre[i+1]]:1);
        for(int k=nxt[i]-1;k>i+1&&pre[k]==i;k--) c1++;
        for(int k=pre[i+1]+1;k<i&&nxt[k]==i+1;k++) c2++;
        ans+=1ll*c1*c2;
        // if(c1||c2) printf("%d:%d,%d\n",i,c1,c2);
    }
    printf("%lld\n",ans);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    main_init();
    int __,_; scanf("%d%d",&__,&_); while(_--)
        main_solve();
    return 0;
}