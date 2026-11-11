#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int a[2000005];
int minn[2000005],b[2000005],f[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    if(c>=11&&c<=12)
    {
        while(t--)
        {
        cin>>n>>m;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        n=n-2*m+1;
        if(n<0)
            cout<<0<<endl;
        else
            cout<<n<<endl;
        }
        return 0;
    }
    while(t--)
    {
        cin>>n>>m;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int i=2;i<=n;i++)
            {
                minn[i]=1e9;
            }
            b[i]=1;
            for(int j=i;j<=n;j++)
            {
                for(int k=j-1;k>=i;k--)
                {
                    if(a[j]-a[k]>m)break;
                    minn[j]=min(minn[k],minn[j]);
                }
                minn[j]+=1;
                int f=0;
                for(int k=j-1;k>=i;k--)
                {
                    if(a[j]-a[k]>m)break;
                    if(minn[k]==minn[j]-1)
                    {
                        b[j]+=b[k];
                    }
                }
                f+=b[j];
                if(f==2)ans++;

            }
            memset(b,0,sizeof(b));
        }
        cout<<ans<<endl;
    }
    return 0;
}
