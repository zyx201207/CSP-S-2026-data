#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, n;
    cin >> c >> n;
    while(n--)
    {
        int t, c;
        cin >> t >> c;
        if(t == 2)
        {
               cout << 0 << endl;
        }else if(t == 3)
        {
               cin >> a[1] >> a[2] >> a[3];
              if(a[3] - a[1] > c && a[2] - a[1] <= c && a[3] - a[2] <= c)
              {
                     cout << 1 << endl;
               }else
              {
                      cout << 0 << endl;
              } 
    }
    return 0;
}
