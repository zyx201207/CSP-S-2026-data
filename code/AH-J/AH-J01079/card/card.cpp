#include<bits/stdc++.h>
using namespace std;
long long a[500050],b[300030],ans[300030];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            if(a[k]==i)
            ans[i]=k;
        }
    }
    for(int k=1;k<=m;k++)
    {
        cout<<ans[k]<<" ";
    }
    return 0;
}
