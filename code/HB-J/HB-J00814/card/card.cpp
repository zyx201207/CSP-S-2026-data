#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int a[500000], i, j, m, n, sum = 0, ans[500000]{};
    cin >> m >> n >> a[0];
    for(i = 1; i < m; i++)
    {
        cin >> a[i];
        if(a[i] == a[i - 1]) for(j = sum; j < n; j++) ans[j]++;
        else sum++;
    }
    for(i = 0; i < n; i++) cout << i + ans[i] + 1 << " ";
    return 0;
}