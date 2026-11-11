#include<bits/stdc++.h>
using namespace std;
int cnt[100005],n,m,x,st[100005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(cnt[x]==0) st[x]=i;
        cnt[x]++;
    }
    for(int i=1;i<=m;i++)
    {
        if(cnt[i]%2==0) cout<<cnt[i]/2<<" ";
        else cout<<st[i]+cnt[i]/2<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}