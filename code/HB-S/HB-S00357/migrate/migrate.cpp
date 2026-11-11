#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[2000006];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j) dfs(i,j);
            }
        }
    }
    return 0;
}
