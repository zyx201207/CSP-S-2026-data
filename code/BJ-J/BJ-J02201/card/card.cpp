#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005], desk[500005],desks[300005],dw=1;
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
    for(int i=1;i<=n;i++)
    {
        dw=1;
        for(int j=i;j<=n;j++)
        {
            if(desks[a[j]]==0)
            {
                dw++;
                desks[a[j]]=dw;
                desk[dw]=a[j];
            }
            else
            {
                dw=dw-desks[a[j]];
                for(int i=dw;i<=5005;i++)
                {
                    if(desks[desk[i]]>=i)
                    {
                        desks[desk[i]]=0;
                        desks[i]=0;
                    }
                }
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(desks[j]!=0)
            {
                ans[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
