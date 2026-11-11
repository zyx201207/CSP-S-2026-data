#include <iostream>
using namespace std ;
int main()
{
    int n, a[1000000] , b = 0 , k;
    string c[100005];
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] >> c[i];
        b = a[1];
        k = a[2];
    }
    if (n == 1)
        cout << 0 ;
    if (n == 2)
    {
        if (b == k)
            cout << 0 ;
        else if ((b + k) % 2 == 0)
        {
            cout << max(b,k);
        }
        else
        {
            cout << (b + k) / 2 ;
        }
    }
    return 0 ;
}
