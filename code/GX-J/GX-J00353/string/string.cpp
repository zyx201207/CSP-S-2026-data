#include <bits/stdc++.h>
using namespace std;

long long cnt, sum;
string c;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    bool f = 0;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        long long x;
        string s;
        cin >> x >> s;
        for(int j = 1;j <= x;j++)
        {
            c += s;
        }
        sum += x;
    }
    for(int i = 0;i < sum;i++)
    {
        if(c[i] == c[sum - 1 - i]) cnt++;
    }
    if(cnt = sum) cout << 0;
    else cout << sum / 2;
}
