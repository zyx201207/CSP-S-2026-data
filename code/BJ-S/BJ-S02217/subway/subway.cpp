#include<bits/stdc++.h>
using namespace std;
int w[500010];
long long k[600];
vector<vector<long long>> a(600,vector<long long>(500010));
//long long a[600][500010];
int t[600][500010];
vector<int> way[600];//经过i站的线路
long long mn=2e18;
void f(int x,int y,long long sum)
{
    for(int i=0;i<way[x].size();i++)
    {
        sum+=t[i][x];
        for(int j=1;j<=k[i];j++)
        {
            sum+=t[i][j];
            if(a[i][j]==y)
            {
                sum+=w[y];
                mn=min(mn,sum);
                break;
            }
            else
            {
                f(a[i][j],y,sum);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n;
    long long m;
    int d,q;
    cin>>c>>n>>m>>d>>q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过、出行计划数
    for(long long i=1;i<=m;i++)
    {
        cin>>w[i];//从每个地铁站的地铁口走到站厅需要的时间
    }
    for(long long i=1;i<=n;i++)
    {
        cin>>k[i];//第 i 条线路经过的地铁站数
        for(long long j=1;j<=2*k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];//第 i 条线路经过的第 j 个地铁站、从该地铁站的站厅走到第 i 条线路的站台需要的时间
            way[a[i][j]].push_back(i);
        }
    }
    while(q--)
    {
        long long x,y;
        cin>>x>>y;//起点和终点所在的地铁站编号

        f(x,y,0);

        cout<<mn+w[x]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
