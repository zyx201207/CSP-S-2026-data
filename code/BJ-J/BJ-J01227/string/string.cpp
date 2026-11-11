#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct sst
{
    ll shu;
    char c;
};

ll n,siz,sum;
string s,a,b;
sst L[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i=1;i<=n;i++)
    {
        cin >> L[i].shu >> L[i].c;
        for (ll j=1;j<=L[i].shu;j++)
        {
            s += L[i].c;
        }
        siz += L[i].shu;
    }
    if (siz%2==0)
    {
        for (ll i=0;i<=siz/2-1;i++)
        {
            a+= s[i];
        }
        for (ll i=siz/2;i<siz;i++)
        {
            b+= s[i];
        }
    }
    else
    {
        for (ll i=0;i<=siz/2-1;i++)
        {
            a+= s[i];
        }
        for (ll i=siz/2+1;i<siz;i++)
        {
            b+= s[i];
        }
    }
    for (ll i=0;i<=siz/2;i++)
    {
        if (a[i]!=b[i])
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}

