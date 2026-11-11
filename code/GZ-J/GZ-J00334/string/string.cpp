//GZ-J00334贵阳市第十六中学曾楠博
#include <bits/stdc++.h>
using namespace std;
int n, a, sum = 0;
string s;
char b;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a >> b;
        for( int j = 1; j <= a; j++ )
        {
            s += b;
        }
    }
    for( int i = 0; i <= n / 2; i++ )
    {
        if( s[i] != s[n - i] ) sum++;
    }
    cout << sum;
    return 0;
}
