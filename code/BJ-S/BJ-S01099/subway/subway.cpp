#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
bool g[1005];
int w[1005];
struct node
{
    int id;
    int tim;
    bool change;
};
void dfs(int v,int fa)
{

}
vector<node> cc[1005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++)
    {
        cin>>w[i];
    }
    for(int i=1; i<=n; i++)
    {
        int du;
        cin>>du;
        for(int j=1; j<=du; j++)
        {
            int a,t;
            if(g[a])
            {
                cc[i].push_back({a,t,1});
            }
            else
            {
                g[a]=1;
                cc[i].push_back({a,t,0});
            }


        }
    }
    while(q--)
    {
        int x,y;
        int qx=0,qy=0,zx=0,zy=0;
        cin>>x>>y;

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<cc[i].size(); j++)
            {
                if(cc[i][j].id==x)
                {
                    qx=i;
                    qy=j;
                    break;
                }

            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<cc[i].size(); j++)
            {
                if(cc[i][j].id==y)
                {
                    zx=i;
                    zy=j;
                    break;
                }

            }
        }
        int it;
        int sum=w[qy];
        int cnt=0;
        while(1)
        {
            cnt++;
            if(cnt==1)it=qx;
            if(it==zx)
            {
                sum+=w[zx];
                cout<<sum;
                return 0;
            }
            int y;
            for(int i=qy; i<cc[it].size(); i++)
            {
                if(cc[it][i].change)
                {
                    y=cc[it][i].id;
                    break;
                }
                sum+=cc[it][i].tim;
            }
            for(int i=1; i<=n; i++)
            {
                for(int j=0; j<cc[i].size(); j++)
                    {
                        if(cc[i][j].id==y&&i!=it)
                        {
                            sum+=cc[i][j].tim;
                            it=i;
                            break;
                        }
                    }
                }

        }

    }








    return 0;
}
