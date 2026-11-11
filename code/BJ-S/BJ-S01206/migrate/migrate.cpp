#include<bits/stdc++.h>
using namespace std;
long long a[2000010],dis[50010],cnt[50010],n,d;
bool check(long long x,long long y,long long tar)
{
    memset(dis,0x6f,sizeof(dis));
    dis[x]=0;
    queue<long long> q;
    q.push(x);
    cnt[x]=1;
    while(q.size())
    {
        long long t=q.front();
        q.pop();
        if(dis[t]+1>tar) continue;
        for(long long i=t+1;i<=y;i++)
        {
            if(a[i]-a[t]>d) break;
            if(dis[i]<dis[t]+1) continue;
            if(dis[i]==dis[t]+1)
            {
                cnt[i]++;
                continue;
            }
            dis[i]=dis[t]+1;
            cnt[i]=cnt[t];
            q.push(i);
        }
    }
    if((dis[y]==tar)&&(cnt[y]==2)) return true;
    return false;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long c,t;
    cin>>c>>t;
    if(11<=c&&c<=12)
    {
        while(t--)
        {
            cin>>n>>d;
            for(long long i=1;i<=n;i++) cin>>a[i];
            long long temp=a[2]-a[1];
            long long len=d/temp;
            if(len<=1)
            {
                cout<<"0\n";
                continue;
            }
            cout<<max(0ll,n-2*len+1)<<'\n';
        }
        return 0;
    }
    if(13<=c&&c<=14)
    {
        while(t--)
        {
            cin>>n>>d;
            for(long long i=1;i<=n;i++) cin>>a[i];
            if(a[n]-a[1]<=d)
            {
                cout<<"0\n";
                continue;
            }
            long long x=0,y=0,z=0;
            for(long long i=1;i<=n;i++)
                if(a[i]-a[1]<=d&&a[n]-a[i]<=d)
                {
                    if(!x) x=i;
                    else if(!y) y=i;
                    else z=i;
                }
            if(z||!y)
            {
                cout<<"0\n";
                continue;
            }
            long long l=1,r=0,ans=0;
            while(l<=n)
            {
                while(r<=n&&a[r]-a[l]<=d) r++;
                if(r>n) break;
                ans+=n-r+1;
                l++;
            }
            cout<<ans<<'\n';
        }
        return 0;
    }
    while(t--)
    {
        cin>>n>>d;
        for(long long i=1;i<=n;i++) cin>>a[i];
        long long ans=0;
        for(long long i=1;i<n;i++)
            for(long long j=i+1;j<=n;j++)
            {
                long long lst=i,cnt=1;
                for(long long k=i+1;k<=j;k++)
                {
                    if(a[k]-a[lst]<=d) continue;
                    if(k-1==lst)
                    {
                        cnt=0;
                        break;
                    }
                    lst=k-1;
                    cnt++;
                }
                if(!cnt) continue;
                if(check(i,j,cnt)) ans++;
            }
        cout<<ans<<'\n';
    }
    return 0;
}
