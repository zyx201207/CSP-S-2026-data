#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
bool flaga=1;
vector<int> a(500005),h(300005),ans(300005),b(500005);
map<int,int> mp;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]<b[i-1]) flaga=0;
    }
    if(flaga)
    {
        for(int i=1;i<=n;i++) mp[b[i]]++;
        int sum=0;
        for(auto i:mp)
        {
            ans[i.first]+=i.second+sum;
            sum+=i.second;
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) a[j]=b[j];
        for(int j=1;j<=m;j++) h[j]=0;
        for(int j=i;j<=n;j++)
        {
            if(h[a[j]])
            {
                int k;
                for(k=j-1;a[k]!=a[j]&&k>=1;k--)
                {
                    h[a[k]]--;
                    a[k]=0;
                }
                a[k]=0;
                h[a[j]]--;
            }
            h[a[j]]++;
        }
        for(int j=i;j<=n;j++) ans[a[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
