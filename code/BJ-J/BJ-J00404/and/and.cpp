#include <bits/stdc++.h>
using namespace std;
char s[200086] , o[36];
int n , a[200086] , l[36];
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    cin >> n;
    for(int i = 0;i < 26;i++)
    {
        o[i] = 'a' + i;
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> s[i];
        for(int j = 0;j < 26;j++)
        {
            if(s[i] == o[j])
            {
                l[j] += a[i];
                break;
            }
        }
    }
    sort(l , l + 26);
    for(int i = 25;i >= 0;i--)
    {
        if(l[i] == l[i + 1])
        {
            cout << l[i];
            return 0;
        }
    }
    cout << 0;
    return 0;
}
