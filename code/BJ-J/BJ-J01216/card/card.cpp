#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("card.in","w",stdin);
freopen("card.out","r",stdout);
int n,m,ans;
cin>>n>>m;
int a[n+1],b[n+1];
for(int i=1;i<=n;i++)
{
    cin>>a[i];

    b[i]=a[i];
}


for(int i=1;i<=n;i++)
{
    for(int k=i;i<=n;k++)
    {

        for(int l=i;i<=k;l++)
        {

            if(a[l]==a[k])
            {
                a[l]=a[k];
                for(int v=l+1;v<=n;v++)
                {

                    a[v]=0;
                }
            }
        }
        for(int e=1;e<=n;e++)
    {
        for(int r=1;r<=n;r++)
        {

            if(b[e]==a[r])
            {
                ans++;
            }
        }

    }
    cout<<ans;
    ans=0;
    }





}


}

