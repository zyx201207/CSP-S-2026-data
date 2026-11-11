#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n, m, a[N];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%ld%ld", &n, &m);
    for(int i=1;i<=n;i++)
    {
        scanf("%ld", &a[i]);
    }
    sort(a+1, a+1+n);
    int ans=-LONG_MAX;
    for(int i=1;i<=n;i++)
    {
        int num=0, cnt=0;
        for(int j=i;j>=1;j--)
        {
            num+=a[i]-a[j];
            cnt++;
            if(num==m)
            {
                break;
            }
            else if(num>m)
            {
                num-=a[i]-a[j];
                cnt--;
                break;
            }
        }
        ans=max(ans, cnt);
    }
    printf("%ld", ans);
    return 0;
}
