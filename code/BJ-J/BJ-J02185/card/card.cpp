#include<bits/stdc++.h>
using namespace std;
int ans[300005],a[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans[a[i]]++;
    }
    for(int i=1;i<=m;i++)
        if(ans[i]>1) cnt++;
    for(int i=1;i<=m;i++)
        if(ans[i]>1&&cnt==1) ans[i]++;
    ans[a[n]]=n;
    for(int j=1;j<=m;j++) cout<<ans[j]<<" ";
    return 0;
}
