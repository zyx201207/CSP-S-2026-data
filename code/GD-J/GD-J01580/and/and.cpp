#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in.txt", "r", stdin);
    freopen("and.out.txt", "w", stdout);
    long long n, m, num[31] = {0};
    cin >> n >> m;
    long long arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];

    }
    sort(arr, arr + n);
    cout << arr[m - 1];
    return 0;
}
