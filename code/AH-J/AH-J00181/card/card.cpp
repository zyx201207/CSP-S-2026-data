#include<bits/stdc++.h>
using namespace std;
int mp[300005],cnt[300005],a[500005],n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    memset(cnt,-1,sizeof cnt);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]=i;
        cnt[a[i]]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            cnt[a[j]]++;
            j=mp[a[j]];
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(cnt[i]!=-1)
            cout<<cnt[i]<<" ";
    }
    return 0;
}
