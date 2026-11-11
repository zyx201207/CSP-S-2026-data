#include <bits/stdc++.h>
using namespace std;

long long n, m, a[200005], pos, maxn;
bool flag=1;

vector<int> v[35];

void er(int x)
{
    int cnt=0, y=a[x];
    while (y != 0)
    {
        cnt++;
        if (y % 2 == 1)
        {
            v[cnt].push_back(x);
        }
        y /= 2;
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        if (a[i] == 2)
        {
            flag = 0;
        }
        er(i);
        maxn = max(maxn, a[i]);
    }
    for (int i=31; i>=1; i--)
    {
        if (v[i].size() >= m)
        {
            pos = i;
            break;
        }
    }
    if (m == 1)
    {
        cout << maxn << endl;
        return 0;
    }
    if (m == 2)
    {
        maxn = 0;
        for (int i=0; i<int(v[pos].size()); i++)
        {
            for (int j=i+1; j<int(v[pos].size()); j++)
            {
                maxn = max(maxn, a[v[pos][i]]&a[v[pos][j]]);
            }
        }
        cout << maxn << endl;
        return 0;
    }
    if (flag)
    {
        cout << pow(2, pos)-1 << endl;
        return 0;
    }
    if (m > n/2)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << pow(2, pos-1) << endl;
    return 0;
}
