#include<bits/stdc++.h>
using namespace std;

int n , m , k , a[2000002] , mx[2000002] , x = 0 , ans;

bool cmp (int x,int y)
{
    return x > y;
}

int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1 , cmp);
    for(int i = 1 ; i <= m ; i ++)
    {
        if(i == 1)
            ans = a[i];
        else
            ans &= a[i];
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
