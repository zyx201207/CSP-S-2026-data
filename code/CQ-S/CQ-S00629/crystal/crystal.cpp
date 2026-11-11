#include<bits/stdc++.h>
bool Mbe;
#define il inline
using namespace std;
typedef double db;
typedef long long ll;
template<typename tt> il bool cmax(tt&x, const tt&y) {return x<y?x=y,1:0; }
template<typename tt> il bool cmin(tt&x, const tt&y) {return y<x?x=y,1:0; }
#define sz(x) ((int)x.size())
#define pub push_back
const int N=5e5;
int n; ll Lim, a[N+3], sm[N+3];
il void solve() {
    cin>>n>>Lim;
    for (int i=1; i<=n; ++i) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1; i<=n; ++i) sm[i]=sm[i-1]+a[i];
    int ans=0;
    a[0]=a[1]-Lim-10, a[n+1]=Lim+a[n]+10;
    for (int m=1; m<=n; ++m) {
        ll L=0, R=max(a[n]-a[m],a[m]-a[1]); // int( )
        for (ll M; L<R; ) {
        M=((L+R+1)>>1);
        // int pr=int( upper_bound(a+1,a+1+n,a[m]+M)-a-1 );  // r]
        int pl=int( lower_bound(a+1,a+1+n,a[m]-M)-a ); // [l, 
        ll smr=0; // ll smr=(sm[pr]-sm[m])-a[m]*ll(pr-m);
        ll sml=a[m]*ll(m-pl) - (sm[m-1]-sm[pl-1]);
        sml+smr<=Lim?L=M:R=M-1;
        // assert(a[pr]<=a[m]+M&&a[pl]>=a[m]-M);
        // assert(a[pr+1]>a[m]+M&&a[pl-1]<a[m]-M);
        }
        ll M=L;
        // int pr=int( upper_bound(a+1,a+1+n,a[m]+M)-a-1 );  // r]
        int pl=int( lower_bound(a+1,a+1+n,a[m]-M)-a ); // [l, 
        ll smr=0; // ll smr=(sm[pr]-sm[m])-a[m]*ll(pr-m);
        ll sml=a[m]*ll(m-pl) - (sm[m-1]-sm[pl-1]);
        ll rem=Lim-(sml+smr), val=min(a[m]-a[pl-1], Lim+10); //a[pr+1]-a[m]);
        // assert(val>Lim||val==M+1);
        // if (pl==1&&pr==n&&ans!=n) cerr << m << endl;
        int pr=m;
        cmax(ans, pr-pl+1+int(rem/val));
        // cerr; if (pr-pl+1+int(rem/val)==n) cerr << m << ' ' << pl << ' ' << pr << ' ' << M << ' ' << rem << endl;
    }
    cout << ans;
}
bool Men;
int main() {
// g++ crystal.cpp -o crystal.exe -O2 -std=c++14 -Wall -Wextra -Wconversion -Wshadow -DMYFRE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef MYFRE
    cerr << "A crystal" << endl;
    cerr << "A crystal" << endl;
    cerr << "A crystal" << endl;
    cerr << "M: " << (db)(&Mbe-&Men)/1024.0/1024 << endl;
#else
#endif 
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
    solve();
    // int testtt; cin>>testtt; for (int ti=1; ti<=testtt; ++ti) solve();
    // int testid, testtt; cin>>testid>>testtt; for (int ti=1; ti<=testtt; ++ti) solve();
#ifdef MYFRE
    cerr << "T: " << (db)clock()/CLOCKS_PER_SEC << endl;
#endif 
}