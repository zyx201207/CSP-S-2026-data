#include <bits/stdc++.h>
using namespace std;

char ch[200005];
int a[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> ch[i];
        while (a[i]--)
        {
            s = s + ch[i];
        }
    }
    int ans = 0;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (i >= len - i - 1)
        {
            break;
        }
        int a = s[i], b = s[len - i - 1];
        //cout << len - i - 1 <<endl;
        if (a != b)
        {
            //cout << a << " " << b <<endl;
            ans++;
        }
    }
    cout <<ans;
    return 0;
}
