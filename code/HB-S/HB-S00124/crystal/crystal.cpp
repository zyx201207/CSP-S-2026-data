#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5*5;
long long n, m, a[N + 5], d[N + 5];
set<long long,greater<long long>> st;
long long v[N + 5];
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n + 1);
    for (int i = n; i >= 1; i--)
    {
        long long sum = m;
        long long q = 0;
        for (int j = i - 1; j >= 1; j--)
        {
            v[j] = a[i] - a[j];
            if (sum > 0)
            {
                sum -= v[j];
                q++;
            }
        }
        st.insert(q + 1);
    }
    for (auto i:st)
    {
        cout << i;
        return 0;
    }
    return 0;
}
