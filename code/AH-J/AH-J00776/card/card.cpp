#include<bits/stdc++.h>
using namespace std;
int a[500005],t[300005],b[500005],k;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            b[++k]=a[j];
            for(int kk=1;kk<=k;kk++)
            {
                if(b[kk]==b[k])
                {
                    for(int y=kk+1;y<=k;y++)
                        b[y]=0;
                    k=kk;
                    break;
                }
            }
        }
        for(int i=1;i<=k;i++)
            t[b[i]]++;
        k=0;
        memset(b,0,sizeof(b));
    }
    for(int i=1;i<=m;i++)
        cout<<t[i]<<' ';
    return 0;
}
