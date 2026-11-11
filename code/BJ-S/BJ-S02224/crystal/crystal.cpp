#include <iostream>
#include <algorithm>
using namespace std;

long long n , m , a[500010] , maxn = 0;

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    for(int i = 1;i <= n;i++)
    {
        long long sum = m , ans = 0 , j = i;
        while(sum >= 0 && j >= 1)
        {
            sum = sum - a[i] + a[j];
            ans++;
            j--;
        }
        if(sum < 0)
        {
            ans--;
        }
        //for(int j = i;j >= 1;j--)
        //{
        //    sum = sum - a[i] + a[j];
        //    if(sum >= 0)
        //    {
        //        ans++;
        //    }
        //}
        if(ans >= maxn)
        {
            maxn = ans;
        }
    }
    cout << maxn << endl;
    return 0;
}
