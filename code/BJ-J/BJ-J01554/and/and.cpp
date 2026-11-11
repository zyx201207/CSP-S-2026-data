#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,maxn=-1;
bool vis[200005];
long long dfs(long long x,long long cnt)
{
    if(x==0) return cnt;
    long long max1=-1;
    for(int i=1;i<=n;i++)
    {
        max1=max(max1,cnt&a[i]);
    }
    return dfs(x-1,max1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        maxn = max(maxn,dfs(m,a[i]));
    }
    cout<<maxn;
    return 0;
}
