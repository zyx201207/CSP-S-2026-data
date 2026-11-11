#include <bits/stdc++.h>
using namespace std;
int ans[105];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105],card[105];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int c=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            card[c]=a[j];
            for(int k=i;k<j;k++)
            {
                if(card[k]==card[c])
                {
                    c=k;
                    card[c]=a[j];
                    break;
                }
            }
        }
        for(int z=i;z<=c;z++)
        {
            if(card[z])
            {
                ans[card[z]++];
            }
        }
        for(int z=i;z<=c;z++)card[z]=0;
    }
    for(int i=0;i<m;i++)cout<<ans[i]<<' ';
    return 0;
}
