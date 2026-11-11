#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],num[300010],ans[300010],last[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        num[a[i]]++;
    }
    for(int i=n; i>=1; i--)
    {
        if(last[a[i]]==0)
        {
            last[a[i]]=i;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(last[a[i-1]]==i-1)
        {
            ans[a[i]]+=ans[a[i-1]];
        }
        if(last[a[i]]==i)
        {
            ans[a[i]]+=num[a[i]];
        }
    }
    for(int i=1; i<=m; i++)
    {
        cout<<ans[i];
        if(i!=m)
        {
            cout<<" ";
        }
    }
    cout<<endl;
}
