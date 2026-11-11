#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 1;
    queue<int> dui;
    for (int i = 0; i < arr.size(); i++)
    {
        dui.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {

    }
    return 0;
}
