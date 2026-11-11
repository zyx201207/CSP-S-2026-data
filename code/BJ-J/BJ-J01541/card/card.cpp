#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool f[500005];
int sum[500005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        memset(f,0,sizeof(f));
        for (int j=i;j<=n;j++)
        {
            if (f[a[j]]==1)
            {
                for (int k=j-1;;k--)
                {
                    f[a[k]]=0;
                    if (a[k]==a[j])
                    {

                        break;
                    }
                }
                f[a[j]]=1;
            }
            else
            {
                f[a[j]]=1;
            }
        }
        for (int j=1;j<=n;j++)
        {

            if (f[j])
            {
                sum[j]++;
            }
        }
    }
    for (int j=1;j<=n;j++)
    {

        if (sum[j]!=0)
        {
            cout<<sum[j]<<" ";
        }
    }
    return 0;
}
