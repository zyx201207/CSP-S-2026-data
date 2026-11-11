#include<bits/stdc++.h>
using namespace std;
int n,m,t,w[500005],ans[505][505];
struct sub
{
    int d,l;
};
struct bfs
{
    int start,x,b;
};
vector<sub> r[505];
vector<int> zt[505];
vector<bfs> dl;
int main()
{
    memset(ans,127,sizeof(ans));
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>n>>n>>m>>t>>t;
    for(int i=1;i<=n;i++)
        ans[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        cin >>w[i];
    }
    for(int i=1,x;i<=n;i++)
    {
        cin >>x;
        for(int j=1,y,z;j<=x;j++)
        {
            cin >>y>>z;
            r[i].push_back({y,z});
            zt[y].push_back(i);
        }
    }
    for(int i=1;i<=m;i++)
    {
        dl.push_back({i,i,w[i]});
    }
    for(int q=0;q<dl.size();q++)
    {
        int start=dl[q].start,x=dl[q].x,b=dl[q].b;
        for(int y:zt[x])
        {
            for(auto i:r[y])
            {
                if(i.d==x)
                {
                    b+=i.l;
                    for(auto z:r[y])
                    {
                        b+=z.l;
                        if(b+w[z.d]<=ans[start][z.d])
                        {
                            ans[start][z.d]=b+w[z.d];
                            dl.push_back({start,z.d,b});
                        }
                        b-=z.l;
                    }
                    b-=i.l;
                    break;
                }
            }
        }
    }
    for(int i=1,x,y;i<=t;i++)
    {
        cin >>x>>y;
        cout<<ans[x][y]<<endl;
    }
    return 0;
}
