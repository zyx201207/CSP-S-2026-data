#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
long long sl[1000010];
long long flag[1000010];
long long lst[10000010];
long long ans[1000010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            sl[j]=0;
            lst[j]=-1;
        }
        for(int j=1;j<=n;j++)
        {
            flag[j]=0;
        }
        for(int j=i;j<=n;j++)
        {
            if(sl[a[j]]>0)
            {
                for(int k=lst[a[j]];k<=j-1;k++)
                {
                    if(flag[k])
                    {
                        sl[a[k]]--;
                        flag[k]=0;
                    }
                }
            }
            sl[a[j]]++;
            flag[j]=1;
            lst[a[j]]=j;
        }
        for(int j=1;j<=m;j++)
        {
            ans[j]+=sl[j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
