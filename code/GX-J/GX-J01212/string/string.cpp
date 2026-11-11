#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    vector<char> arr;
    int n;
    cin >> n;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        char a;
        cin >> t >> a;
        for (int j = 0; j < t; j++)
        {
            arr.push_back(a);
            index++;
        }
    }
    int m = (arr.size() + 1) / 2;
    int len = arr.size();
    int c = 0;
    for (int i = 0; i < m; i++)
    {
        if (arr[i] != arr[len - 1 - i])
        {
            c++;
        }
    }
    cout << c << endl;
    return 0;
}
