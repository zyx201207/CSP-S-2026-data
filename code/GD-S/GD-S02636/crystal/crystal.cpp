#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

long long int n;
long long int m;
long long crystals[500009];
long long int cc = LLONG_MIN;
long long int res;


/*
bool ok(long long int f)
{
    cc = 0;
    long long int u = m;
    for (int i = 1;i <= n;i++)
    {
        if (crystals[i] < f && u - crystals[i] >= 0)
        {
            u -= crystals[i];
            cc++;
        }
        if (crystals[i] == f) cc++;
    }
}


bool cmp(const long long &a, const long long&b)
{
    return a > b;
}

*/


int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    long long int mmax = LLONG_MIN;
    long long int mmin = LLONG_MAX;
    for (int i = 1;i <= n;i++)
    {
        cin >> crystals[i];
        mmax = max(mmax,crystals[i]);
        mmin = min(mmin,crystals[i]);
    }
    sort(crystals+1,crystals+n+1);
    //long long int l = mmin;
    //long long int r = mmax;
    //long long int ans = 0;
    long long lastC = 0;
    long long lastCO = 0;
    long long int mmaxx_1 = 1;
    for (int i = 2;i <= n;i++)
    {
        long long int k = m;
        long long int ct = 1;

        if (lastC > 0&& lastCO > 0 && lastC * (crystals[i]-crystals[i-1]) + lastCO < k)
        {
            ct = lastC + 1;
            lastCO = (lastC * (crystals[i]-crystals[i-1]) + lastCO);
            lastC = ct;
            mmaxx_1 = max(mmaxx_1,ct);
            continue;
        }

        for (int j = i - 1; j >= 1;j--)
        {
            if (crystals[j] == crystals[i])
            {
                ct++;
            }
            else if (k - (crystals[i] - crystals[j]) >= 0)
            {
                ct++;
                k -= crystals[i]-crystals[j];
            }
            else
            {
                break;
            }
        }
        mmaxx_1 = max(mmaxx_1,ct);
        lastC = ct;
        lastCO = m - k;
    }
    cout << mmaxx_1;
    return 0;
}
