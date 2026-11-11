#include <iostream>
#include <algorithm>
using namespace std;

int a[200005];
char c[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    long long len = 0;
    cin >> n;
    string s = "";
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> c[i];
        len += a[i];
        for (int j = 1; j <= a[i]; ++j) s = s + c[i];
    }
    //cout << s << "\n";
    s = "&" + s;
    long long ans = 0;
    for (int i = 1; i <= len / 2; ++i)
    {
        if (s[i] != s[len + 1 - i]) ans++;
        //cout << s[i] << " " << s[len + 1 - i] << endl;
    }
    cout << ans;
    return 0;
}
