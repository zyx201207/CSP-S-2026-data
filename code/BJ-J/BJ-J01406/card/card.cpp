#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int c[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]==a[i])
            {
                for(int r=i+1;r<=j;r++)
                {
                    c[a[r]]=r-i;
                }
                i=j;
            }
        }
        c[a[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}
