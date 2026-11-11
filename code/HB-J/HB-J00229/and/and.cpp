#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    long long n, m, num;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        for(int j = i; j >= 1; j ++)
        {
            long long b = a[i], c = a[j];
            num = max(b & c, num);
        }
    }

    cout << num;

    return 0;
}
