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
const int maxn=2e6+10;

int a[maxn],s[maxn],c[maxn];
int n,d;

void work()
{
    /* Code */
    cin>>n>>d; int tar=0;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        s[i]=0,c[i]=1; int res=1,nxt=0;
        for(int j=i+1,l=i; j<=n; j++)
        {
            while(a[j]-a[l]>d) { res-=c[l++]; if(res==0) res=nxt,nxt=0; }
            if(l==j) break;
            s[j]=s[l]+1; c[j]=res; nxt+=c[j];
            if(c[j]==2) tar++;
        }
    }
    cout<<tar<<'\n';
    return;
}

signed main()
{
    fileio("migrate.in","migrate.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,stTime=clock();
    cin>>t>>t;
    while(t--) work();
    // cerr<<"Time : "<<(double)(clock()-stTime)/CLOCKS_PER_SEC<<'\n';
    return 0;
} // Cellinia Texas.