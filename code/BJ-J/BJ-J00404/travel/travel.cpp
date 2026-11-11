#include <bits/stdc++.h>
using namespace std;
int n , m , a[100086];
int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i < n;i++)
    {
        if(a[i] = a[i + 1])
        {
            a[i + 1] = 0;
        }
    }
    sort(a + 1 , a + n + 1);
    cout << a[m];
    return 0;
}
