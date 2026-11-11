#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 2; i <= n ;i++)
    {
        long long c = 0;
        int s = i;
        while(s >= 2)
        {
            c += a[i] - a[i - 1];
            a[i - 1] = a[i];
            s--;
        }
        if(c > m)
        {
            cout << c - 1;
            break;
        }
    }
    return 0;
}
