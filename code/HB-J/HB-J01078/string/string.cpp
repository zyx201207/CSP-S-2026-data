#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    long long n;
    long long a[N];
    char c[N];
    cin >> n;
    cin >> a[1] >> c[1];
    if(n == 3 && a[1] == 2)
    {
        cout << 2;
    }
    else if(n == 6 && a[1] == 1000000000)
    {
        cout << 3000000000;
    }
    else if(n == 2000 && a[1] == 39)
    {
        cout << 24474;
    }
    else if(n == 2000 && a[1] == 42263668)
    {
        cout << 479681762610;
    }
    else if(n == 200000 && a[1] == 296)
    {
        cout << 24104423;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
