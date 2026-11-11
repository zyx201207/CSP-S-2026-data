#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 +5;

struct Node
{
    int num;
    char c;
}a[N];
int n, ans;
string s = "";
int main ()
{
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].num >> a[i].c;
        for (int j = 1; j <= a[i].num; j++)
        {
            s = s + a[i].c;
        }
    }
    for (int i = 0; i < s.size () / 2; i++)
    {
        if (s[i] != s[s.size () - i - 1])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
