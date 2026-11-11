#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
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
        for(int j=1;j<=n;j++)
        {
            if(a[i]==a[j])
            {
                a[i]=0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0)
        {
            cout<<a[i]<<" ";
        }
        else
        {
                continue;
        }
    }
    return 0;
}
