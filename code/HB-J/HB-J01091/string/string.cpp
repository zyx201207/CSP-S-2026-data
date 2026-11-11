#include <bits/stdc++.h>
using namespace std;
int n;
double middle;
struct a_string
{
    long long a;
    char c;
    string String;
};
a_string s[25];
long long size_of_string;
string sss = {};
string ss = {};
void init ( )
{
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> s[i].a >> s[i].c;
        for (int j = 1;i <= s[i].a;i++)
        {
            s[i].String += s[i].c;
        }
        sss += s[i].String;
        size_of_string += s[i].a;
    }
    for (int i = 0;i < n;i++)
    {
        ss[i] = sss[size_of_string - i];
    }
    middle = n / 2 + 1;
    return;
}
int main ( )
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    init ( );

    long long ans = 0;

    for (int i = 0;i < size_of_string / 2;i++)
    {
        if (sss[i] != ss[i])
        {
            ans++;
            cout << ans << ' ';
        }

    }
     cout << sss;
    cout << ans;
    return 0;
}
