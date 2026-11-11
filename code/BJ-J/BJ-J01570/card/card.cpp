#include<bits/stdc++.h>
using namespace std;
int b[300005];
//bool c[500005];
//int a[300005];
int ans[300005];
int p[500005];
int n,m;
int main()
{freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
    cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>p[i];
}
for(int i=1;i<=n;i++)
{
    for(int j=i;j<=n;j++)
    {
        if(b[p[j]]!=0)
        {
        for(int k=b[p[j]];k<=j;k++)
        {
            b[p[k]]=0;
        }
        }b[p[j]]=j;
    }
    for(int j=1;j<=n;j++)
    {
    ans[j]+=(b[j]?1:0);
    }
    memset(b,0,sizeof(b));
}
for(int i=1;i<=m;i++)
{
    cout<<ans[i]<<' ';
}
}
