#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int nxt[N];
int tmp[N];
int ans[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(tmp[a[i]]!=0)
        {
            nxt[tmp[a[i]]]=i;
        }
        tmp[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        memset(tmp,0,sizeof tmp);
        int ind=i;
        while(ind<=n)
        {
            while(nxt[ind]!=0) ind=nxt[ind];
            tmp[a[ind]]++;
            ind++;
        }
        for(int j=1;j<=m;j++) if(tmp[j]!=0) ans[j]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}