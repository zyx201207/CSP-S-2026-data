#include<bits/stdc++.h>
using namespace std;
int f[500005],a[500005];
int cnt[300005];
int next_[500005],last[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    memset(next_,0x3f,sizeof next_);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        next_[last[a[i]]]=i;
        last[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            while(next_[j]<=n)
            {
                j=next_[j];
            }
            cnt[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<" ";
    return 0;
}
