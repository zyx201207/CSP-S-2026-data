#include<bits/stdc++.h>
using namespace std;
long long t,n,c;
long long d,a[5005],dis[5005],cnt[5005][5005];
void dijstra(int s)
{
    for(int i=1;i<=n;i++) dis[i]=1e18;
    priority_queue<pair<long long,int>,vector<pair<int,int>>,greater<pair<int,int> > > q;
    q.push({0,s});
    dis[s]=0;
    while(!q.empty())
    {
        pair<long long,int> u=q.top();
        q.pop();
        int point=u.second;
        int bound=upper_bound(a+1,a+n+1,a[point]+d)-a-1;
        for(int i=point+1;i<=bound;i++)
        {
            if(dis[i]==dis[point]+1)
            {
                cnt[s][i]++;
                //cout<<i<<endl;
                q.push({dis[i],i});
            }
            else if(dis[point]+1<dis[i])
            {
                dis[i]=dis[point]+1;
                q.push({dis[i],i});
            }
        }
    }
    //for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    //cout<<endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    //cout<<c<<" "<<t<<endl;
    //getchar();
    while(t--)
    {
        cin>>n>>d;
        //cout<<n<<" "<<d<<endl;
        //getchar();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            //cout<<a[i];
        }
        long long ans=0;
        if(c<=10)
        {
            for(int i=1;i<=n;i++)
            {
                dijstra(i);
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(cnt[i][j]==1) ans++;
                    cnt[i][j]=0;
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
