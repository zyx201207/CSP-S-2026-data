#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005];
int n,m;
int b[200005][505];
void card(int q)
{
    if(q==n)
    {
        ans[a[n]]++;
        return;
    }
    if(b[a[q]][b[a[q]][0]]==q)
    {
        ans[a[q]]++;
        card(q+1);
    }
    else
    {
        card(b[a[q]][b[a[q]][0]]);
    }
    return;
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]][++b[a[i]][0]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        card(i);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
