#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<char> a;
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        char y; cin >> y;
        for(int j = 1; j <= x; j++)
        {
            a.push_back(y);
        }
    }
    int num = 0;
    for(int i = 0; i < a.size() / 2; i++)
    {
        if(a[i] != a.back())
        {
            num ++;
        }
        a.pop_back();
    }
    cout << num;
    return 0;
}
