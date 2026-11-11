#include <bits/stdc++.h>
using namespace std;
int n , m , a[100860] , l , o;
int main()
{
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] == m)
        {
            l++;
        }
        else
        {
            o += a[i];
        }
    }
    cout << m << " " << l << o;
    return 0;
}