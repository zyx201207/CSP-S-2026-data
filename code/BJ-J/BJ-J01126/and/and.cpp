#include<bits/stdc++.h>
using namespace std;
bool a[200005][32],c[200005];
int b[33];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,z;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        int j=0;
        while(t)
        {
            int t1=t%2;
            a[i][j]=t1;
            b[j]=b[j]+t1;
            t/=2;
            j++;
        }
    }
    int i;
    for(i=31;i>=0;i--)
    {
        if(b[i]>=m)
            break;
    }
    z=i-m;
    for(int j=1;j<=n;j++)
    {
        if(a[j][i]==1)
        {
            c[j]=1;
        }
    }
    int ans=0;
    for(int j=i;j>=0;j--)
    {
        int d[200005];
        int flag=0;
        for(int k=1;k<=n;k++)
        {
            if(c[k]==0)continue;
            flag+=a[k][j];
            if(a[k][j]==0)
            {
                d[k]=1;
            }
        }
        if(flag>=m)
        {
            ans+=pow(2,j);
            for(int k=1;k<=n;k++)
            {
                if(d[k])
                {
                    c[k]=0;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}