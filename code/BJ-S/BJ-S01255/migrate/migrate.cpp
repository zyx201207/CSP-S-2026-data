#include<bits/stdc++.h>
using namespace std;
int C,t,ans=0;
int n,d;
struct node
{
    int id,x;
};
vector<node> a[5005];
int c[5005];
int dis1[5005];
int sum[5005][105];
bool operator<(node x,node y)
{
    return x.x>y.x;
}
void bfs(int s)
{
    priority_queue<node> q; 
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++){
        dis1[i]=1e9;
    }
    q.push({s,0});
    dis1[s]=0;
    sum[s][0]=1;
    while(!q.empty())
    {
        int tx=q.top().id,ty=q.top().x;
        q.pop();
        for(node i:a[tx])
        {
            if(dis1[i.id]>dis1[tx]+i.x)
            {
                dis1[i.id]=dis1[tx]+i.x;
                sum[i.id][ty+1]=sum[tx][ty];
                q.push({i.id,ty+1});
            }
            else if(dis1[i.id]==(dis1[tx]+i.x))
            {
                sum[i.id][ty+1]+=sum[tx][ty];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(sum[i][j]==2){
                ans++;
            }
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>t;
    while(t--)
    {
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)cin>>c[i];
        sort(c+1,c+1+n);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if((c[j]-c[i])<=d)a[i].push_back({j,c[j]-c[i]});
            }
        }
        for(int i=1;i<=n;i++)
        {
            bfs(i);
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)a[i].clear();
    }
    return 0;
}