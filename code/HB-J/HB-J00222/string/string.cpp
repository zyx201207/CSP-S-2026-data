#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,num[200005],s[200005],cnt1 = 0,cnt2 = 0;
    cin >> n;
    for (long long i = 1;i <= n;i++)
    {
        cin >> num[i] >> s[i];
        cnt1 += num[i];
    }
    string st;
    for (long long i = 1;i <= n;i++)
    {
        for (long long j = 1;j <= num[i];j++)
        {
            st += s[i];
        }
    }
    for (int i = 0;i <= cnt1 - 1;i++)
    {
        if (s[i] != s[cnt1 - i])
        {
            cnt2++;
        }
    }
    cout <<cnt2 / 2;
}
