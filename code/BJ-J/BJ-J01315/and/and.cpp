#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long ans[200005];
int way;
int cnt;
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = i;j < n;j++)
        {
            ans[cnt] = a[i];
            if(j+m <= n)
            {
                for(int k = 1;k <= m;k++)
                {
                    ans[cnt] = int(ans[cnt]&a[j+k]);
                }
                cnt++;
            }
        }
    }
    sort(ans,ans+cnt,cmp);
    cout << ans[0];
    return 0;
}
