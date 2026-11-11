#include<bits/stdc++.h>
using namespace std;
int a[500005],h[500005],b[500005];
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
        int cnt=0;
        memset(b,0,sizeof b);
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=cnt;k++)
            {
                if(b[k]==a[j])
                {
                    cnt=k-1;
                  //  cout<<i<<" "<<j<<" "<<k;
                    break;
                }
            }
            b[++cnt]=a[j];
        }
        for(int ii=1;ii<=cnt;ii++)
        {
            h[b[ii]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<h[i]<<" ";
    }
    return 0;
}
