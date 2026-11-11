#include <bits/stdc++.h>
using namespace std;
const int N=500005;
const int M=300005;
int n,m,a[N],nxt[N],us[N],ans[M],pos[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(pos[a[i]]!=0)
            nxt[pos[a[i]]]=i;
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++) us[i]=1;
    for(int i=1;i<=n;i++)
    {
        if(nxt[i]==0)
        {
            ans[a[i]]+=us[i];
            us[i+1]+=us[i];
        }
        else
        {
            us[nxt[i]]+=us[i];
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}