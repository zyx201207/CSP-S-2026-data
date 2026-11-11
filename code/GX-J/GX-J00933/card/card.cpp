#include<bits/stdc++.h>
using namespace std;
long long n,a[500001],dl[400001],ans[500001],m,len;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        len=1;
        dl[1]=a[i];
        for(int j=i;j<=n;j++)
        {
            for(int l=len;l>=1;l--)
            {
                 if(dl[l]==a[j])
                 {
                     len=l-1;
                     break;
                 }
            }
            len++;
            dl[len]=a[j];
        }
        for(int j=1;j<=len;j++)
        {
            ans[dl[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

