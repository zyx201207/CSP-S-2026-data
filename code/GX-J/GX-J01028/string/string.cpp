#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string S,m;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x >> m;
        for(int j = 1;j <= x;j++)
        {
            S += m;
        }
    }
    cout << S;
    return 0;
}
