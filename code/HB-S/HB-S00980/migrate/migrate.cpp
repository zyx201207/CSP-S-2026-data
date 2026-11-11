#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,a[2234567],l[5005][5005],f[5005][5005],ans;
signed main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                l[i][j]=1e18;
                f[i][j]=0;
                if(i==j)
                    l[i][j]=0;
                else if(abs(a[i]-a[j])<=d)
                {
                    l[i][j]=1;
                    l[j][i]=1;
                }
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(l[i][j]>l[i][k]+l[k][j])
                        l[i][j]=l[i][k]+l[k][j],f[i][j]=0;
                    else if(l[i][j]==l[i][k]+l[k][j])
                    {
                        f[i][j]=1;

                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                ans+=f[i][j];
                cout<<i<<' '<<j<<endl;
            }

        cout<<ans/4;
    }
	return 0;
}
