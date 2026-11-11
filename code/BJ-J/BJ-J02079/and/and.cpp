#include <bits/stdc++.h>
using namespace std;

int n,m,a[200005],b[200005],twom[35],ans2;
int s[200005][31];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    twom[0]=1;
    for(int i=1;i<=31;i++)
        twom[i]=twom[i-1]*2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=31;j>=0;j--)
        {
            s[i][j]=a[i]/twom[j];
            a[i]%=twom[j];
        }
    }
    for(int i=0;i<=31;i++)
    {
        int cnt=0,ans;
        bool flag=0;
        for(int j=1;j<=n;j++)
        {
            if(s[j][i]==1)
            {
                if(flag==0)
                {
                    ans=b[j];
                    flag=1;
                }
                cnt++;
                ans=(ans&b[j]);
            }
            if(cnt>=m)
            {
                ans2=max(ans2,ans);
            }
        }
    }
    cout<<ans2;
    return 0;
}