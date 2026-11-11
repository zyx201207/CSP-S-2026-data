#include<bits/stdc++.h>
using namespace std;
int vis[300010];
int cnt[300010];
int a[300010];
int b[300010];
int n,q,k;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
       cout<<cnt[k]<<" ";
    }
    return 0;
}
