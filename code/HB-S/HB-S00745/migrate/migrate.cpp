#include<bits/stdc++.h>
using namespace std;
int c,T;
long long n,d;
long long x[3000005];
int pre[3000005];
int dis[3000005],cnt[3000005];
int bfs(int s)
{
    for(int i=1;i<=n;i++)
    {
        cnt[i]=dis[i]=0;
    }
    queue<int> q;
    q.push(s);
    dis[s]=1,cnt[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=u+1;v<=pre[u];v++)
        {
            if(dis[v]==0)
            {
                dis[v]=dis[u]+1,cnt[v]=cnt[u];
                q.push(v);
            }
            else if(dis[v]==dis[u]+1)
            {
                cnt[v]+=cnt[u];
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==2)
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n;i++)
        {
            int l=i+1,r=n,mid,ans=-1;
            while(l<=r)
            {
                mid=((l+r)>>1);
                if(x[mid]-x[i]<=d)
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            pre[i]=ans;
        }
        long long ans=0;
        if(c==11 || c==12)
        {
            int l=pre[1]-1;
            if(l==-2 || l==1)
            {
                cout<<"0\n";
                continue;
            }
            for(int i=1;i+l+l-1<=n;i++)
            {
                ans+=1;
            }
            cout<<ans<<"\n";
            continue;
        }
        if(c==13 || c==14)
        {
            for(int i=1;i<n;i++)
            {
                if(pre[i]==-1)
                {
                    break;
                }
                int l=pre[pre[i]-2],r=pre[pre[i]-1];
                if(pre[i]==i+1)
                {
                    continue;
                }
                if(r==-1)
                {
                    r=n;
                }
                ans+=(r-l);
            }
            cout<<ans<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            ans+=bfs(i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}