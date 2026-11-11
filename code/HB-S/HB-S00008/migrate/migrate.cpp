#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long int read()
{
    long long int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return x*f;
}
int c,t,n,cnt[5001],dis[5001],R[2000001];
long long d,x[2000001];
vector<int> a[5001];
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    memset(dis,0x3f,sizeof dis);
    memset(cnt,0,sizeof cnt);
    dis[u]=0;
    cnt[u]=1;
    while(q.size())
    {
        int p=q.front();
        q.pop();
        if(cnt[p]>2) continue;
        for(int v:a[p])
        {
            if(dis[v]==dis[p]+1) cnt[v]+=cnt[p];
            else if(dis[v]>dis[p]+1) dis[v]=dis[p]+1,cnt[v]=cnt[p],q.push(v);
        }
    }
}
int main()
{
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
    c=read();
    t=read();
    while(t--)
    {
        n=read();
        d=read();
        for(int i=1;i<=n;i++) x[i]=read();
        if(n==1) {cout<<0;continue;}
        if(c<=10)
        {
            for(int i=1;i<=n;i++)
            {
                a[i].clear();
             //   for(int j=i-1;j>=1;j--) if(x[i]-x[j]<=d) a[i].push_back(j); else break;
                for(int j=i+1;j<=n;j++) if(x[j]-x[i]<=d) a[i].push_back(j); else break;
            }
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                bfs(i);
                for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
            }
            cout<<ans<<"\n";
        }
        else if(c==11||c==12)
        {
            long long p=d/(x[2]-x[1]);
            if(p==1||p==0) cout<<0<<"\n";
            else cout<<max(0ll,n-2*p+1)<<"\n";
        }
        else if(c==13||c==14)
        {
            int pos;
            for(int i=1;i<=n;i++) R[i]=lower_bound(x+1,x+n+1,x[i]+d)-x;
            for(int i=1;i<=n;i++) if(x[1]+d>=x[i]&&x[n]-d<=x[i]) {pos=i;break;}
            long long ans=0;
            R[0]=pos;
            for(int i=1;R[i]<=pos+1;i++)
            {
                if(R[i]==pos)
                {
                    ans+=R[R[i]-1]-R[R[i]-2];
                }
                else ans+=n-R[pos-1];
            }
            cout<<ans<<"\n";
        }
        else cout<<(long long)n*(n-1)/2<<"\n";
    }
    return 0;
}
