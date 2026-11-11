#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m,a[500010],vis[300010],cnt[300010];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        vis[a[i]]++;
    }
    int flag=0;
    for(int i=n;i>=1;i--)
    {
        if(i==n)
        {
            cnt[a[i]]=i;
            vis[a[i]]=1;
        }
        else if(cnt[a[i]]!=1&&vis[a[i]]!=1)
        {
            cnt[a[i]]=i-flag;
            vis[a[i]]=1;
            flag++;
        }
        else if(cnt[a[i]]!=1&&vis[a[i]]==1&&a[i]!=a[n])
        {
            flag--;
        }
        else if(cnt[a[i]]==1&&vis[a[i]]!=1)
        {
            cnt[a[i]]=i-flag+1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
