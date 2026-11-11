#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],b[500005];
bool ok=true;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i-1]>a[i])
        {
            ok=false;
            break;
        }
    }
    if(ok==true)
    {
        for(int i=1;i<=m;i++)
        {
            cout<<n<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            b[j]=j;
        }
        for(int j=i;j<=n;j++)
        {
            bool flag=false;
            for(int k=1;k<=m;k++)
            {
                if(b[k]==a[j])
                {
                    flag=true;
                    for(int t=k+1;t<=m;t++)
                    {
                        b[t]=0;
                    }
                }
            }
            if(flag==false)
            {
                int tmp=0;
                for(int k=1;k<=m;k++)
                {
                    if(b[k]==0)
                    {
                        tmp=k;
                        break;
                    }
                }
                b[tmp]=a[j];
            }
        }
        for(int j=1;j<=m;j++)
        {
            cnt[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
