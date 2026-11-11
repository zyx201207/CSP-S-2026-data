#include<bits/stdc++.h>
using namespace std;
int a[500015],n,m,ans[300015];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans[a[i]]=i;
    }
    cout<<ans[1];
    for(int i=2;i<=m;i++)
        cout<<" "<<ans[i];
    fclose(stdin);
    fclose(stdout);
}
