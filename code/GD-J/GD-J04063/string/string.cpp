#include <bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long n;
    string s;
    cin >> n;

    bool is_sa = 1;
    for(long long i = 1;i <= n;i ++)
    {
        cin >> a[i] >> c[i];
        if((i != 1) && (a[i - 1] != a[i]))
        {
            is_sa = 0;
        }
    }


    long long cnt = 0;
    if(is_sa)
    {
        for(int i = 1;i <= n;i ++)
        {
            s += c[i];
        }
        for(long long i = 0;i <= (s.size() / 2 - 1);i ++)
        {
            if(s[i] != s[s.size() - i - 1])
            {
                cnt += a[1];
            }
        }
        cout << cnt;
        return 0;
    }

    for(long long i = 1;i <= n;i ++)
    {
        for(long long j = 1;j <= a[i];j ++)
        {
            s += c[i];
        }
    }

    for(long long i = 0;i <= (s.size() / 2 - 1);i ++)
    {
        if(s[i] != s[s.size() - i - 1])
        {
            cnt ++;
        }
    }
    cout << cnt;

    return 0;
}
