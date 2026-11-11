#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N];
int c,t,n,d;
int cnt=0;
int dp[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        cout<<cnt<<endl;
        cnt++;
    }
    return 0;
}
