#include <bits/stdc++.h>
using namespace std;

unsigned long long num[5005][5005] = {0};
long long sum = -1;

void add(long long arr[], long long x, long long y, long long n, unsigned long long m)
{
    if((x - y + 1) < sum)
        return ;
    if(x == (n - 1) && y == (n - 1))
        return ;
    if(x == y)
        num[x][y] = 0;
    else if (x < y)
        return ;
    else
    {
        if((num[x - 1][y] + (arr[x] - arr[x - 1]) * (x - y)) > m)
            num[x][y] = m + 1;
        else
            num[x][y] = num[x - 1][y] + (arr[x] - arr[x - 1]) * (x - y);
    }
    if(num[x][y] <= m && (x - y + 1) > sum)
        sum = x - y + 1;
    if(y < (n - 1))
        add(arr, x, y + 1, n, m);
    if(x < (n - 1))
        add(arr, x + 1, y, n, m);
}

int main()
{
    freopen("crystal.in.txt", "r", stdin);
    freopen("crystal.out.txt", "w", stdout);
    long long n;
    unsigned m;
    cin >> n >> m;
    long long arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    add(arr, 0, 0, n, m);
    cout << sum;
    return 0;
}
