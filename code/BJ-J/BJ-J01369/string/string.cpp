#include <iostream>
using namespace std;
#define int long long
int a[200010];
char s[200010];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> s[i];
    }
    int l = 1, r = n;
    int nowl = a[1], nowr = a[n];
    int sum = 0;
    while(l < r)
    {
        if(nowl > nowr)
        {
            if(s[l] != s[r])
            {
                sum += nowr;
            }
            r--;
            nowl -= nowr;
            nowr = a[r];
        }
        if(nowl < nowr)
        {
            if(s[l] != s[r])
            {
                sum += nowl;
            }
            l++;
            nowr -= nowl;
            nowl = a[l];
        }
        if(nowl == nowr)
        {
            if(s[l] != s[r])
            {
                sum += nowl;
            }
            l++;
            r--;
            nowl = a[l];
            nowr = a[r];
        }
    }
    cout << sum;
    return 0;
}