#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n , a[1e9] , c[1e9] , sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        cin >> c[i];
    }
    int s = (sum - 1) * 10;
    for(int i = 1; i <= sum; i++)
    {

    }
return 0;
}
