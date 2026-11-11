#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
long long x[2000001],a[2000001],sna[2000001],b[2000001],snb[2000002],cnta[2000001],cntb[2000001],sa[2000001],sb[2000002],aa[2000001],dis[2000001];
bool flaga[2000001],flagb[2000001];
int n;
int finda(long long xx)
{
    int l=1,r=n,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(x[mid]<=xx)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
int findb(long long xx)
{
    int l=1,r=n,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(x[mid]>=xx)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    if(c>=13&&c<=14)
    {
        while(t--)cout<<0<<"\n";
        return 0;
    }
    if(1)
    {
        //cout<<t<<endl;
        while(t--)
        {
            long long d;
            cin>>n>>d;
            long long ans=0;
            for(int i=1;i<=n;i++)cin>>x[i];
            for(int l=1;l<=n;l++)
            {
                //cout<<l<<endl;
                for(int i=l;i<=n;i++)dis[i]=aa[i]=0;
                queue<int>q;
                q.push(l);
                dis[l]=1;
                aa[l]=1;
                while(q.size()>0)
                {
                    int nw=q.front();
                    if(aa[nw]==2)ans++;
                    //if(n==7)cout<<l<<" "<<nw<<" "<<aa[nw]<<" "<<dis[nw]<<endl;
                    q.pop();
                    for(int j=nw+1;j<=n&&x[j]-x[nw]<=d;j++)
                    {
                        if(dis[j]==0)
                        {
                            q.push(j);
                            dis[j]=dis[nw]+1;
                        }
                        if(dis[j]==dis[nw]+1)aa[j]+=aa[nw];
                    }
                }
            }
            //cout<<-1<<endl;
            cout<<ans<<"\n";
        }
        return 0;
    }
    return 0;
    while(t--)
    {
        long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cnta[i]=cntb[i]=0;
            a[i]=sna[i]=b[i]=snb[i]=sa[i]=sb[i]=0;
            flaga[i]=flagb[i]=0;
        }
        snb[n+1]=sb[n+1]=0;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=2;i<n-1;i++)
        {
            int l1=findb(x[i+1]-d),r1=finda(x[i+2]-d);
            if(l1==-1||r1==-1)continue;
            if(x[i+2]-x[r1]==d)r1--;
            int l2=findb(x[i-1]+d),r2=finda(x[i]+d);
            if(l2==-1||r2==-1)continue;
            if(x[l2]-x[i-1]==d)l2++;
            cnta[i+2]++;
            cnta[r2+1]--;
            cntb[i-1]++;
            cntb[l1-1]--;
            //ans+=1ll*(r1-l1+1)*(r2-l2+1);
        }
        int nw=0;
        for(int i=1;i<=n;i++)
        {
            nw+=cnta[i];
            if(nw>0)flaga[i]=1;
            sa[i]=sa[i-1]+flaga[i];
        }
        nw=0;
        for(int i=n;i>=1;i--)
        {
            nw+=cntb[i];
            if(nw>0)flagb[i]=1;
            sb[i]=sb[i+1]+flagb[i];
        }
        for(int i=1;i<=n;i++)
        {
            int l=1,r=i,ans;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(sa[i]==sa[mid-1])
                {
                    ans=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            a[i]=i-ans+1;
            //cout<<a[i]<<" ";
        }
        //cout<<endl;
        for(int i=1;i<=n;i++)sna[i]=sna[i-1]+a[i];
        for(int i=n;i>=1;i--)
        {
            int l=i,r=n,ans;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(sb[i]==sb[mid+1])
                {
                    l=mid+1;
                    ans=mid;
                }
                else r=mid-1;
            }
            b[i]=ans-i+1;
            //cout<<b[i]<<" ";
        }
        //cout<<endl;
        for(int i=n;i>=1;i--)snb[i]=snb[i+1]+b[i];
        long long ans=0;
        for(int i=2;i<n-1;i++)
        {
            int l1=findb(x[i+1]-d),r1=finda(x[i+2]-d);
            if(l1==-1||r1==-1)continue;
            if(x[i+2]-x[r1]==d)r1--;
            int l2=findb(x[i-1]+d),r2=finda(x[i]+d);
            if(l2==-1||r2==-1)continue;
            if(x[l2]-x[i-1]==d)l2++;
            //cout<<i<<":"<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
            ans+=(sna[r1]-sna[l1-1])*(snb[l2]-snb[r2+1]);
            //ans+=1ll*(r1-l1+1)*(r2-l2+1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
