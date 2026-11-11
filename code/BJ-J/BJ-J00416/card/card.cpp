#include<bits/stdc++.h>
using namespace std;
int a[500010],b[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
        ans+=b[i];
        cout<<ans<<" ";
    }
    return 0;
}
