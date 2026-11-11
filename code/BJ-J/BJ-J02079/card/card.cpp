#include <bits/stdc++.h>
using namespace std;

int n,m,card[1000000],ans[1000000],table[1000000];
int a[1000000];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>card[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(a[card[j]]==0)
            {
                a[card[j]]=j;
                table[j]=card[j];
            }
            else
            {
                for(int z=a[card[j]];z<=j-1;z++)
                {
                    a[table[z]]=0;
                    table[z]=0;
                }
                a[card[j]]=j;
                table[j]=card[j];
            }
        }
        for(int z=i;z<=n;z++)
        {
            ans[table[z]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
