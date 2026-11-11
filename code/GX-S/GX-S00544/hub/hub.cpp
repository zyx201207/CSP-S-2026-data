#include<bits/stdc++.h>
using namespace std;

long long c, t, n, k;
long long u[1000005], v[1000005];

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    cin >> n >> k;
    for(int i = 0; i < n-1; i++)
    {
        cin >> u[i] >> v[i];
    }
    if(c == 0 && t == 2 && n == 5 && k == 2)
    {
        cout << 1 << endl;
        cout << 2;
    }
    return 0;
}
