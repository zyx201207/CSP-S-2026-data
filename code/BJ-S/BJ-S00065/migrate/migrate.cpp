#include<bits/stdc++.h>
using namespace std;
int a[2000010],dis[5050][5050];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        memset(dis,0x3f,sizeof dis);
        for(int i=1;i<=n;++i)
        {
            for(int j=i;j<=n;++j)
            {
                    dis[i][j]=dis[j][i]=a[j]-a[i];
            }
        }
        int ans=0;
            for(int i=1;i<=n;++i)
            {
                for(int j=i+2;j<=n;++j)
                {
                    int cnt=0;
                    if(dis[i][j]<=d)cnt=1000;
                    for(int k=i+1;k<j;++k)
                    {
                        if(dis[i][k]<=d&&dis[k][j]<=d)cnt++;
                    }
                    if(cnt==2)
                    {
                        ans++;
                    }
                }
            }
        cout<<ans<<endl;

    }
    return 0;
}
