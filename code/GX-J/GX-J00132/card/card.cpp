#include <iostream>
using namespace std ;
int main()
{
    long long n , m ,x,table[3000000];, v[3000005];
    int a[300005];
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    x = n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    for (int h = 1 ; h <= n ; h++)
    {
        for (int i = x ; i <= n ; i++)
        {
            if (a[i] == a[i+1]){
                for (int j = 1 ; j <= i ; j++)
                {
                    a[j] = 0 ;
                }
            }
            table[i] = a[x];
        }
        x += 1 ;
        for (int u = 1 ; u <= 300005;u++)
        {
            if (table[u] == h)
            {
                v[h] += 1;
            }
        }
    }
    for (int i = 1 ; i <= 300005;i++)
    {
        cout << v[h] << " ";
    }
    return 0 ;
}
