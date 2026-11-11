#include <bits/stdc++.h>

using namespace std;

long long n, a, len, cc;
char c;
string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a >> c;
        for(long long j = 1; j <= a; j++)
        {
            s += c;
        }
    }

    len = s.size();
    long long i = 0;
    long long j = len - 1;
    while(i <= j)
    {
        if(s[i] != s[j]) cc++;
        i++;
        j--;
    }

    cout << cc;
    return 0;
}
