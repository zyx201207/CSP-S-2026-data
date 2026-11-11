#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n , m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    int maxn = 0;
    if(m == 2)
    {
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= n - 1; j ++)
            {
                int cnt = a[i] & a[j + 1];
                if(cnt > maxn)
                {
                    maxn = cnt;
                }
            }
        }
    }
    if(m == 1)
    {
        for(int i = 1; i <= n; i ++)
        {
            if(a[i] > maxn)
            {
                maxn = a[i];
            }
        }
    }
    cout << maxn;
    return 0;
}
