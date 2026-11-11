#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10005];
int main()
{
    freopen("and.in","w",stdin);
    freopen("and.out","r",stdout);
    cin >> n >> m;
    for(int i= 1;i <= n;i++)
    {

        cin >> a[i];
    }
    int maxn = 0,cnt = 0;
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= n;j++)
        {
            maxn = a[i] & a[j-i];
            if(maxn >= cnt)
            {
                cnt = maxn;
            }
        }
    }
    cout << cnt;
    return 0;
}
