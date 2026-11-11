#include <bits/stdc++.h>

using namespace std;
int sta[510];
struct way{
    int to,w;
};
way c[1010];
int dis[510];
queue <int> q;
vector <vector<way>> e;
int cc,d;//c n m d q
int n,m,qq;//the number of ways,station number,the number of plans
void dij(int x)
{
    q.push(x);
    for(int i=1;i<=n;i++)
    {
        dis[i]=1e9;
    }
    dis[x]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto d:e[u])
        {
            if(dis[d.to]>dis[u]+d.w)
            {
                dis[d.to]=dis[u]+d.w;
                q.push(d.to);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>cc>>m>>n>>d>>qq;
    for(int i=1;i<=n;i++)
    {
        cin >>sta[i];
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        cin >>x;
        for(int k=1;k<=x;k++)
        {
            cin >>c[k].to>>c[k].w;
        }
        for(int j=1;j<=x;j++)
        { //cout <<"1"<<endl;
            e[c[j].to].push_back({c[j+1].to,c[j].w});
            e[c[j+1].to].push_back({c[j].to,c[j+1].w});
        }
    }

    for(int i=1;i<=qq;i++)
    {
        int l,r;
        cin >>l>>r;//cout <<"2"<<endl;
        dij(l);
        cout <<sta[l]+sta[r]+dis[r]<<endl;
    }
    return 0;
}
