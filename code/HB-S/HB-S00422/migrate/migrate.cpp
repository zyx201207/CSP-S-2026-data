#include<bits/stdc++.h>
using namespace std;
long long t,n,m,a[2000005],ans,vis[2000005],l;
bool bj;
struct node
{
    long long a,b;
};
queue<node> q;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    cin>>t;
    while(t--)
    {
        bj=1;
        cin>>n>>m;
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])
            {
                bj=0;
            }
        }
        if(bj)
        {
            if(a[2]-a[1]>m||a[3]-a[1]<m)
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<n-3<<endl;
            }
            continue;
        }
        for(long long i=n;i>=1;i--)
        {
            if(q.size()&&q.front().b-m>a[i])
            {
                vis[q.front().a]=i+1;
                q.pop();
            }
            q.push({i,a[i]});
        }
        while(q.size())
        {
            vis[q.front().a]=1;
            q.pop();
        }
        l=n;
        ans=0;
        for(long long i=n;i>=1;i--)
        {
            l=max(vis[i]-1,1LL);
            while(i>=3&&vis[i-1]<=l&&vis[i-2]<=l&&(vis[i-3]>l||i-3==l))
            {
                ans++;
                l--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
