#include<bits/stdc++.h>
using namespace std;
int a[205];
int dis[205],cnt[205];
int n,d;
void dfs(int k,int ds)
{
    if(dis[k]>ds)dis[k]=ds,cnt[k]=1;
    else if(dis[k]==ds)cnt[k]++;
    int r=k+1;
    while(a[r]-a[k]<=d&&r<=n)
    {
        dfs(r,ds+1);
        ++r;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;++i)cin>>a[i];
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            memset(dis,0x3f,sizeof(dis));
            memset(cnt,0,sizeof(cnt));
            dfs(i,0);
            for(int j=i;j<=n;++j)if(cnt[j]==2)++ans;
        }
        cout<<ans<<endl;
    }
}