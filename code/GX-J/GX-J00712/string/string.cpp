#include <bits/stdc++.h>
using namespace std;
long long n, a, cnt = 0, sum = 0, pos = 0, flag;
bool op;
char s[200005];
string x = "";
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> s[i];
        sum += a;
        for (int j = 1; j <= a; j++)
        {
            x[pos] = s[i];
            pos++;
        }
        if (i == 1) continue;
        else if (s[i] == s[i - 1]) op = true;
        else op = false;
    }
    if (op)
    {
        cout << 0;
        return 0;
    }
    pos = 0;
    if (x.size() % 2 == 1) flag = 1;
    else flag = 0;
    while (pos != sum / 2 + flag)
    {
        if (x[0 + pos] == x[x.size() - 1 - pos])
        {
            continue;
        }
        else
        {
            cnt++;
        }
        pos++;
    }
    cout << cnt;
    return 0;
}
