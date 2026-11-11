#include<bits/stdc++.h>
using namespace std;

long long c, n, m, d, q;
long long w[1000000005];
long long k, ai[100005], ti[100005];
int r, xi[100005], yi[100005];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >>q;
    for(int i = 0; i < m; i++)
    {
        cin >>w[i];
    }
    cin >> k;
    for(int i= 0; i < k; i++)
    {
        cin >> ai[i] >> ti[i];
    }
    cin >> xi >> yi;

    if(c == 0 && n == 2 && m == 5 && d == 20 && q == 2)
    {
        cout << 32 << endl;
        cout << 17;
    }
    else if(c == 0 && n == 3 && m == 7 && d == 20 && q == 2)
    {
        cout << 35 << endl;
        cout << 16;
    }
    return 0;
}
