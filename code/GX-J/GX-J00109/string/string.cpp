#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,sum = 0;
    string s = "";
    char c;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a >> c;
        for (int j = 1;j <= a;j++)
        {
            s = s + c;
        }
    }
    int k = ceil(s.size() * 1.0 / 2);
    for (int i = 0;i <= k;i++)
    {
        int j = s.size() - (i + 1);
        if (i > j) break;
        if (s[i] != s[j])
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
