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

void get_max(int &w1,cint w2)
{ if(w2>w1) w1=w2; }
void main_init()
{

}
cint N=500020;
int n; LL m;
LL a[N];
void main_solve()
{
    scanf("%d%lld",&n,&m);
    For(i,1,n) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int ans=0; LL w=0ll;
    for(int r=1,l=1;r<=n;r++)
    {
        while(w>m)
        {
            w-=(a[r]-a[l]);
            l++;
        }
        get_max(ans,r-l+1);
        if(r<n) w+=((a[r+1]-a[r])*(r-l+1));
    }
    printf("%d\n",ans);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    main_init();
    // int _; scanf("%d",&_); while(_--)
        main_solve();
    return 0;
}