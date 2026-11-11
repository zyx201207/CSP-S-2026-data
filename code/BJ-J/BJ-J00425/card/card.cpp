#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn],last[maxn];
int ans[maxn];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        last[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int x=i;
        while(x<n)
        {
            ans[a[x]]++;
            x=last[a[x]]+1;
        }
    }
    ans[a[n]]=n;
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
