#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[2]-a[1]==a[n]-a[n-1])
    {
        int sum=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            if(m>=sum)
                ans++;
            sum+=i*(a[n]-a[n-1]);

        }
        cout<<ans;
    }
    else
    {
        long long minn=-1;
        long long b[1005][1005],c[5005];
        for(int i=1;i<=n;i++)
        {
            b[i][a[i]]=0;
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    if(a[j]<a[i])
                    {
                        b[i][a[j]]=a[j]-a[i];
                    }
                    else
                        b[i][a[j]]=0;
                }
            }
            for(int k=1;k<=n;k++)
            {
                c[i]+=b[i][k];
            }
            if(m>=c[i])
                minn=i;
        }
        cout<<minn;
    }
    return 0;
}
