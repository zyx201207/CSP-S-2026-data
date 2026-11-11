#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],k[3000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long l=1;
    for(int q=1;q<=n;q++)
    {
        for(int i=q;i<=n;i++)
        {
            b[l]=a[i];
            for(int j=i;j>=1;j++)
            {
                if(b[j]==a[i])
                {
                    l=j;
                }
            }
            l++;
        }
        for(int h=1;h<=l;h++)
        {
            k[b[h]]+=1;
        }
        l=1;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<k[i];
    }
    return 0;
}
