#include<bits/stdc++.h>
using namespace std;
long long a[200001],dis[200001],t[200001],w=0,d[200001];
void dfs(long long n,long long m,long long c)
{
    long long i,k;
    if(c==m+1){k=d[1];for(i=2;i<=m;i++)k&=d[i];w++;t[w]=k;}
    for(i=c;i<=n;i++)
        if(dis[i]==0)
        {
            dis[i]=1;
            d[c]=a[i];
            c++;
            dfs(n,m,c);
            c--;
            dis[i]=0;
        }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long maxn,i,n,m;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    dfs(n,m,0);
    maxn=t[1];
    for(i=2;i<=w;i++)
    if(t[i]>maxn)maxn=t[i];
    cout<<maxn;
    return 0;

}
