#include <bits/stdc++.h>

using namespace std;

#define int long long

#define fileio(x,y) freopen(x,"r",stdin),freopen(y,"w",stdout);
#define tup tuple<int,int,int>
#define fir(x) (get<0>(x))
#define sec(x) (get<1>(x))
#define thr(x) (get<2>(x))
#define pii pair<int,int>
#define bit(x) bitset<x>
#define pb emplace_back
#define i12 __int128_t
#define mt make_tuple
#define mp make_pair

const int mod=998244353;
const int maxn=5e5+10;

int a[maxn],sa[maxn];
int n,m;

void work()
{
    /* Code */
    cin>>n>>m; int l=1,res=0;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++) sa[i]=sa[i-1]+a[i];
    for(int i=1; i<=n; i++)
    {
        while(l<i&&a[i]*(i-l+1)-(sa[i]-sa[l-1])>m) l++;
        res=max(res,i-l+1);
    }
    cout<<res<<'\n';
    return;
}

signed main()
{
    fileio("crystal.in","crystal.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,stTime=clock();
    t=1;
    while(t--) work();
    // cerr<<"Time : "<<(double)(clock()-stTime)/CLOCKS_PER_SEC<<'\n';
    return 0;
} // Cellinia Texas.