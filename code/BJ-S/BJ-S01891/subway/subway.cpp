#include<bits/stdc++.h>
#define ll long long
using namespace std;
int w[500005];
ll t[505][505];
struct stop
{
    int line;
    int time;
};
struct node
{
    int num;
    int step;
};
vector<stop> s[405];
vector<int> l[505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,Q,i,j,x,y;
    cin>>c>>n>>m>>d>>Q;
    for(i=1;i<=m;i++)
        cin>>w[i];
    for(i=1;i<=n;i++)
    {
        int v;
        cin>>v;
        for(j=1;j<=v;j++)
        {
            int a,t;
            cin>>a>>t;
            s[a].push_back({i,t});
        }
    }
    memset(t,0x3f,sizeof(t));
    for(i=1;i<=m;i++)
    {
        for(j=0;j<s[i].size();j++)
        {
            stop ss=s[i][j];
            for(int u=0;u<j;u++)
            {
                t[ss.line][s[i][u].line]=min(t[ss.line][s[i][u].line],(ll)ss.time+s[i][u].time);
                t[s[i][u].line][ss.line]=min(t[s[i][u].line][ss.line],(ll)ss.time+s[i][u].time);
            }
        }
    }/*
    for(i=1;i<=m;i++)
    {
        cout<<i<<":\n";
        for(j=0;j<s[i].size();j++)
            cout<<s[i][j].line<<" "<<s[i][j].time<<"\n";
    }*/
    //cout<<t[1][2]<<" "<<t[1][3]<<" "<<t[2][3]<<"\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            if(t[i][j])
            {
                l[i].push_back(j);
                l[j].push_back(i);
            }
        }
    }
    queue<node> q;
    while(Q--)
    {
        cin>>x>>y;
        bool f[505]={};
        for(i=0;i<s[x].size();i++)
            q.push({s[x][i].line,s[x][i].time});
        ll ans=1e15;
        int e[505],en=0;
        for(i=0;i<s[y].size();i++)
            e[++en]=s[y][i].line;
        while(q.size())
        {
            node cur=q.front();
            q.pop();
            if(f[cur.num])
                continue;
            //cout<<cur.num<<" ";
            f[cur.num]=1;
            bool flag=0;
            for(i=1;i<=en;i++)
            {
                if(cur.num==e[i])
                {
                    ans=min(ans,(ll)cur.step+s[y][e[i]].time+w[x]+w[y]);
                    flag=1;
                    break;
                }
            }
            if(flag)
                continue;
            for(i=0;i<l[cur.num].size();i++)
            {
                int nxt=l[cur.num][i];
                q.push({nxt,cur.step+t[cur.num][nxt]});
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
