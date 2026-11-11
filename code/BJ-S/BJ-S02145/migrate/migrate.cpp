#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, d, x[2000010], f[5010][5010], xmin[5010];
void dfs(int u, int bu)
{
    //cout<<u<<' '<<bu<<endl;
    for(int i=u+1;i<=n;i++)
    {
        if(x[i]-x[u]>d)break;
        f[i][bu+1]++;
        xmin[i]=min(xmin[i], bu+1);
        dfs(i, bu+1);
        //cout<<"tc"<<endl;
    }
}
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        if(c==11||c==12)
        {
            int cd=x[2]-x[1], xx;
            xx=d/cd;
            cout<<n-(2*xx-1)<<endl;
        }
        else if(c<=10)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                memset(f, 0, sizeof(f));
                memset(xmin, 0x3f3f3f3f, sizeof(xmin));
                dfs(i, 0);
                for(int j=i+1;j<=n;j++)
                {
                    if(xmin[j]!=4557430888798830399&&f[j][xmin[j]]==2)
                    {
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/