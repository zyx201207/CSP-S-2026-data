#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6+10;
int n, d, x[N], a[N], lian[N];
double ou[N];

bool check(int u)
{
    return x[u+2]-x[u]<=d && x[u+3]-x[u+1]<=d && x[u+3]-x[u]>d;
}

void calc()
{
    memset(ou, 0, sizeof ou);
    cin >>n >>d;
    for(int i=1; i<=n; i++)
        cin >>x[i];
    int j=1;
    for(int i=1; i<=n; i++)
    {
        j = max(j, i);
        while(j<n && x[j+1]-x[j]<=d){j++;}
        lian[i] = j;
    }
    int c = 0;
    for(int i=1; i<=n-3; i++)
        if(check(i)) a[++c] = i;
    if(c==0)
    {
        cout <<0 <<'\n';
        return;
    }
    int ans = lian[a[c]]-a[c]-3 +c;
    for(int i=a[1]-1; i>=1; i--)
        if(x[i+1]-x[i]<=d) ans++;
        else break;
    for(int i=1; i<=c-1; i++)
        if(a[i+1]-a[i]==3)
            ans += 4;
        else if(a[i+1]-a[i]>3)
            ans += 2*min(lian[a[i]], a[i+1]+2)-a[i];
        else if(a[i+1]==a[i]+1)
        {
            ou[i+1] = ou[i]+0.5;
            ans += ou[i+1];
        }
    cout <<ans <<'\n';
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, t;
    cin >>c >>t;
    while(t--)
    {
        calc();
    }
    return 0;
}