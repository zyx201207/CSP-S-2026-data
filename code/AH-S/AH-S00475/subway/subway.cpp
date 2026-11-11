#include<bits/stdc++.h>
using namespace std;
int n,m,T,Wi[500005],Ki,Aik[500005],Tik[500005],Xr,Yr;
int v[505][25][505][2],cnt[505],cntt[505][505],vis[505];
long long ans,mark[505];
struct node
{
    int x;
    long long step;
    friend bool operator < (node a,node b)
    {
        return a.step>b.step;
    }
};
priority_queue<node> q;
inline void bfs()
{
    while(!q.empty())
    {
        node t=q.top();
        q.pop();
        if(t.x==Yr)
        {
            if(ans==0)ans=t.step;
            else if(t.step<ans)ans=t.step;
        }
        for(int i=1;i<=cnt[t.x];i++)for(int j=1;j<=cntt[t.x][i];j++)
        if((vis[v[t.x][i][j][1]]==0||t.step+v[t.x][i][j][0]<mark[v[t.x][i][j][1]])&&(t.step+v[t.x][i][j][0]<ans||ans==0))
        {
            vis[v[t.x][i][j][1]]=1,mark[v[t.x][i][j][1]]=t.step+v[t.x][i][j][0];
            q.push(node{v[t.x][i][j][1],mark[v[t.x][i][j][1]]});
        }
    }
    cout<<ans+Wi[Xr]+Wi[Yr]<<endl;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>T>>T;
    for(int i=1;i<=m;i++)cin>>Wi[i];
    for(int i=1;i<=n;i++)
    {
        cin>>Ki;
        for(int j=1;j<=Ki;j++)cin>>Aik[j]>>Tik[j];
        for(int j=1;j<=Ki;j++)
        {
            cnt[Aik[j]]++;
            for(int k=1;k<=Ki;k++)if(j!=k)
            {
                cntt[Aik[j]][cnt[Aik[j]]]++;
                v[Aik[j]][cnt[Aik[j]]][cntt[Aik[j]][cnt[Aik[j]]]][0]=Tik[j]+Tik[k];
                v[Aik[j]][cnt[Aik[j]]][cntt[Aik[j]][cnt[Aik[j]]]][1]=Aik[k];
            }
        }
    }
    for(int i=1;i<=T;i++)
    {
        cin>>Xr>>Yr;
        vis[Xr]=1,ans=0;
        q.push(node{Xr,0});
        bfs();
        memset(vis,0,sizeof(vis));
        memset(mark,0,sizeof(mark));
    }
    return 0;
}
