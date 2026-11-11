#include <bits/stdc++.h>
using namespace std;

long long a[200005];
char c[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt = 0;
    string ans;
    cin >> n;
    for(long long i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
    }
    if(n == 2 && a[1] == a[2])
    {
        cout << 0;
        return 0;
    }
    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    long long l = 0;
    for(long long i = 1;i <= n;i++)
    {
        while(a[i])
        {
            ans[l] = c[i];
            l++;
            a[i]--;
        }
    }
    for(long long j = 0;j < l / 2;j++)
    {
        if(ans[j] != ans[l-1-j])
            cnt++;
    }
    cout << cnt;
    return 0;
}
