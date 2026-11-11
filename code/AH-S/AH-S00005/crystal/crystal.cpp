#include<bits/stdc++.h>
#define int long long
using namespace std;
int n = 0, m = 0, L = 0, R = 0, mid = 0, ans = 0;
vector<int>v;
bool check(int x)
{
    if(n > 5000)
    {
        int sum = 0;
        for(int i = 0; i < x; i++)
        {
            sum += v[x - 1] - v[i];
            if(sum > m)return false;
        }
        return true;
    }
    else
    {
        for(int Bge = 0; Bge + x - 1 < n; Bge++)
        {
            int sum = 0;
            for(int i = Bge; i < Bge + x - 1; i++)
            {
                sum += v[Bge + x - 1] - v[i];
                if(sum > m)break;
            }
            if(sum <= m)return true;
        }
        return false;
    }
}
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    /*
    for(int j=1; j<n; j++)
    {
        cf[0][j] = v[j] - v[0];
    }
    */
    L = 0; R = n;
    while(L <= R)
    {
        mid = L + (R - L) / 2;
        if(check(mid))
        {
            ans = mid;
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
