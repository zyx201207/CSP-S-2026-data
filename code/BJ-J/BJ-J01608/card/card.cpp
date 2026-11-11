#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],b[500005],cnt,ans[300005],flag;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1])flag=1;
    }
    if(flag)
    {
        for(int i=1;i<=n;i++)
        {
            cnt=i-1;
            memset(t,0,sizeof(t));
            for(int j=i;j<=n;j++)
            {
                if(t[a[j]])
                {
                    int f=0;
                    for(int k=i;k<=cnt;k++)
                    {
                        if(f)t[b[k]]=0;
                        if(b[k]==a[j])f=k;
                    }
                    cnt=f;
                }
                else
                {
                    b[++cnt]=a[j];
                    t[a[j]]=1;
                }
            }
            for(int j=i;j<=cnt;j++)ans[b[j]]++;
        }
        for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        memset(t,0,sizeof(t));
        for(int j=i;j<=n;j++)
        {
            if(!t[a[j]])b[++cnt]=a[j];
            t[a[j]]=1;
        }
        for(int j=1;j<=cnt;j++)ans[b[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}