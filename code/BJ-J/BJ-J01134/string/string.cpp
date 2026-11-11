#include <iostream>

using namespace std;
using ll = long long;

struct long_string
{
    ll a;
    char c;
}s[200005];
int n;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i].a >> s[i].c;
    int l = 1, r = n, cnt = 0, i = 1, j = s[n].a;
    while (l < r){
        if (s[l].c != s[r].c)
            cnt++;
        if (++i > s[l].a)
        {
            i = 1, l++;
        }
        if (--j < 1)
        {
            j = s[--r].a;
        }
    }
    cout << cnt << endl;
    return 0;
}
