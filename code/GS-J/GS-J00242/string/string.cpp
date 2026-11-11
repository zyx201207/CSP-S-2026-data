#include <iostream>
#include <cstdio>

using namespace std;

const int N = 2e5 + 5;

int n, a[N];
long long ans;
char c[N];
string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        for (int j = 1; j <= a[i]; j++)
        {
            s += c[i];
        }
    }
    //cout << s;
    long long i = 0, j = s.size() - 1;
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            ans++;
            s[i] = s[j];
        }
    }
    cout << ans;
    return 0;
}
