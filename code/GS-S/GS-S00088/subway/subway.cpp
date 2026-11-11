#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,k[505],c,d,q,w[500005],t[505][20005],a[505][20005],aa[505][20005];
struct sub
{
    int s,l;
}suw[100005];
int main()
{
int tt;
for(int i = 0;i < n;i++)
{
    for(int j = 0;j < n;j++)
    {
        a[i][j]=0x3f3f3f3f;
    }
}
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i = 0;i < m;i++)cin>>w[i];
for(int i = 0;i < n;i++)
{
    cin>>k[i];
    for(int j = 0;j < k[i];j++)
    {
        cin>>a[i][j]>>t[i][j];
        aa[i][a[i][j]]=t[i][j];
    }
}
for(int i = 0;i < q;i++)
{
    cin>>suw[i].s>>suw[i].l;
}
for(int k = 0;k < n;k++)
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(a[i][j]>a[i][k]+a[k][j])
            {
                a[i][j]=a[i][k]+a[k][j];
            }
        }
    }
}
for(int i = 0;i < q;i++)
{
    int ans=0;
    ans=w[suw[i].s-1]+w[suw[i].l-1]+aa[suw[i].s-1][suw[i].s]+aa[suw[i].s-1][suw[i].l];
    cout<<ans<<endl;
}
return 0;
}
