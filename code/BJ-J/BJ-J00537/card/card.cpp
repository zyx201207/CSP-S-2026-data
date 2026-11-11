#include <bits/stdc++.h>
using namespace std;
int a[500001],t[500001],cnt[500002],l[500001],sum[300001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>0;i--)
    {
        if(l[a[i]]==0)
        {
            l[a[i]]=i;
            t[i]=i+1;
        }
        else
        {
            t[i]=l[a[i]];
            a[i]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        sum[a[i]]+=++cnt[i];
        cnt[t[i]]+=cnt[i];
    }
    for(int i=1;i<=m;i++)
        cout<<sum[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
