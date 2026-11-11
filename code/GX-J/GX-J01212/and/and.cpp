#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    vector<int> arr;
    int n, g;
    cin >> n >> g;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int z = arr[0];
    for (int i = 1; i < g; i++)
    {
        z = (z & arr[i]);
    }
    cout << z;
    return 0;
}
