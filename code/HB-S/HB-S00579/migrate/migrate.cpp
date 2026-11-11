#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define fi first
#define se second

const int N = 2e6+10;

int n;
ll d,x[N];
int L[N],R[N];
int lcnt[N],rcnt[N];
ll suml[N],sumr[N];

void solve()
{
    cin >> n >> d;
    for(int i=1;i<=n;i++)
    {
        cin >> x[i];
        suml[i] = sumr[i] = 0;
    }
    L[1] = 0;
    int j=1;
    for(int i=2;i<=n;i++)
    {
        while(x[i] - x[j] > d) j++;
        L[i] = j;
    }
    R[n] = n+1;
    j = n;
    for(int i=n-1;i>=1;i--)
    {
        while(x[j] - x[i] > d) j--;
        R[i] = j;
    }
    for(int i=1;i<=n;i++)
    {
        // cerr << L[i] << ' ' << R[i] << '\n';
        if(R[i] > i)
        {
            lcnt[R[i]] ++;
            if(L[R[i]] == i) lcnt[R[i]] += lcnt[i];
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(L[i] < i)
        {
            rcnt[L[i]]++;
            if(R[L[i]] == i) rcnt[L[i]] += rcnt[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(R[i] > i+1) suml[R[i]]++;
        if(L[i] < i-1) sumr[L[i]]++;
    }
    ll ans=0;
    for(int i=2;i<n-1;i++)
    {
        ll l=suml[i+1],r=sumr[i];
        // cerr << l << ' ' << r << '\n';
        if(R[L[i]] == i+1) l+=lcnt[L[i]];
        if(L[R[i+1]] == i) r+=rcnt[R[i]];
        ans += l*r;
        // cerr << i << ' ' << l*r << '\n';
    }
    cout << ans << '\n';
}
void init()
{
    memset(L,0,sizeof(int)*(n+2));
    memset(R,0,sizeof(int)*(n+2));
    memset(lcnt,0,sizeof(int)*(n+2));
    memset(rcnt,0,sizeof(int)*(n+2));
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cid,T;
    cin >> cid >> T;
    while(T--)
    {
        solve();
        init();
    }
}