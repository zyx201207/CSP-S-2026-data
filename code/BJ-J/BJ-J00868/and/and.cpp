#include <bits/stdc++.h>
using namespace std;
const int N=300005;
long long n,m,k,sum;
int s[N],vis[32];
bool a[N][32],ans[32];
void dfs(int r,int last)
{
    for(int i=0;i<=30;i++) vis[i]=0;
    for(int i=1;i<=r;i++)
    {
        for(int j=0;j<=30;j++)
        {
            vis[j]+=a[s[i]][j];
        }
    }
    int maxn=-1;
    for(int i=last-1;i>=0;i--)
    {
        if(vis[i]>=m)
        {
            maxn=i;
            break;
        }
    }
    if(maxn==-1) return;
    ans[maxn]=1;
    int s1=0;
    for(int i=1;i<=r;i++)
    {
        if(a[s[i]][maxn])
        {
            s[++s1]=s[i];
        }
    }
    dfs(s1,maxn);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=0;j<=30;j++)
        {
            if(k&(1<<j))
            {
                a[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++) s[i]=i;
    dfs(n,30);
    for(int i=0;i<=30;i++)
    {
        if(ans[i]) sum+=(1<<i);
    }
    cout<<sum;
    return 0;
}