#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n , a[1000000];
    char c[100];
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if( c[i] == c[i + 1])
        {
            cout << "0";
        }
        if( a[i] == a[i+2] and a[i+1] % 2 == 0)
        {
            cout << a[i];
        }
    }
    return 0;
}
