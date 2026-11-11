#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = n; i >= 2; i--)
    {
        long long sum = 0;
        for(int j = i - 1; j >= 1; j--)
            sum += a[i] - a[j];
        if(sum > m)
            continue;
        else
        {
            cout << i;
            return 0;
        }
    }
    cout << "1";
    return 0;
}
