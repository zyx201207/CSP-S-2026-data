#include<bits/stdc++.h>
using namespace std;
int a[500010],f[300010],flg[300010];
int n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=j;i<=n;i++)
        {
            if(f[a[i]]==0)
                f[a[i]]=1;
            else if(f[a[i]]==1)
                memset(f,0,sizeof f);
        }
        for(int i=1;i<=m;i++)
        {
            if(f[i]==1)
                flg[i]++;
        }
    }
    for(int i=1;i<=m;i++)
    {

        cout<<flg[i]<<' ';
    }
    return 0;
}
