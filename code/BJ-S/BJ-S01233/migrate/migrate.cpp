#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
const int N=2e6+7;
long long c,n,d,m,x[N],cnt[N],dis[N];
bool check(long long x,long long y)
{
    if(x<=0&&y>=0)
    {
        return abs(x)-d+y<=0;
    }
    else if(x<=0&&y<=0)
    {
        return y-x<=d;
    }
    else //x>=0&&y>=0
    {
        return y-x<=d;
    }
}
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    dis[s]=0;
    cnt[s]=1;
    while(q.size())
    {
        int a=q.front();
        q.pop();
        if(c==13||c==14)
        {
            if(dis[a]>=2)continue;
        }
        for(int b=a+1;b<=n&&check(x[a],x[b]);b++)
        {
            //if(cnt[b]>2||dis[a]+1>dis[b])continue;
            if(cnt[b]==0)
            {
                dis[b]=dis[a]+1;
                cnt[b]=cnt[a];
                q.push(b);
            }
            else if(dis[a]+1==dis[b]){
                //cout<<x<<"//"<<y<<endl;
                cnt[b]+=cnt[a];
            }
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    scanf("%lld",&c);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        scanf("%lld",&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x[i]);
        }
        if(c==11||c==12)
        {
            long long ans=0,c=x[2]-x[1],cs=d/c;
            for(int l=1;l<n;l++)
            {
                if(l<=cs)continue;
                long long n2=l/cs,n3=l%cs;
                if(n3==0)continue;
                if(n2!=1)continue;
                if(l-cs+1<cs)continue;
                ans+=n-l+1;
            }
            cout<<ans<<endl;
            continue;
        }
        long long ans=0;
        for(int s=1;s<=n;s++)
        {
            bfs(s);
            for(int i=s+1;i<=n;i++)
            {
                //cout<<x[i]<<":"<<cnt[i]<<" ";
                if(cnt[i]==2)
                {
                    //cout<<s<<"->"<<i<<" ";
                    ans+=1;
                }
            }
            //cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
