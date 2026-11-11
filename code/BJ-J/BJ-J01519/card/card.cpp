#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000010];
int box[300010];
int mp[300010];
int x[1000010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int flag=1;
    for(int i=2;i<=n;i++)if(a[i]<a[i-1])flag=0;
    if(flag==1)
    {
        for(int i=1;i<=n;i++)box[a[i]]++;
        for(int i=1;i<=m;i++)box[i]+=box[i-1];
        for(int i=1;i<=m;i++)cout<<box[i]<<' ';
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int tmp=0;
        memset(mp,0,sizeof(mp));
        for(int j=i;j<=n;j++)
        {
            if(mp[a[j]]==0)x[++tmp]=a[j],mp[a[j]]=tmp;
            else
            {
                for(int k=mp[a[j]]+1;k<=tmp;k++)mp[x[k]]=0,x[k]=0;
                tmp=mp[a[j]];
            }
        }
        for(int j=1;j<=tmp;j++)
        {
            box[x[j]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<box[i]<<" ";
    return 0;
}
