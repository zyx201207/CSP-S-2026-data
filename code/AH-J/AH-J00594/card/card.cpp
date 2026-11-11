#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int u[300005];
int x[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        x[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int t=i;
        for(int j=i;j<=m;j++)
        {
            for(int k=j+1;k<=m;k++)
            {
                if(a[j]==a[k]){
                    t=k;
                }
            }
        }
        for(int j=t;j<=n;j++)
        {
            u[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<u[i]<<" ";
    }
    return 0;
}
