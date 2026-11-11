#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005],k;
struct sb
{
    long long a,t;
}s[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c;
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];//从每个地铁站的地铁口走到站厅需要的时间
    for(int i=1;i<=n;i++)
    {
        cin>>k;//第 i 条线路经过的地铁站数
        for(int j=1;j<=k;j++)
        {
            cin>>s[i][j].a>>s[i][j].t;//a表示经过的第 j 个地铁站
            //t 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
        }
    }

    while(q--)
    {
        long long tim=0;
        int x,y,z;
        cin>>x>>y;
        tim+=w[x];
        while(x!=y)
        {
            for(int i=1;i<=n;i++)
            {
                if(s[i][1].a==x)
                {
                    tim+=s[i][1].t;
                    tim+=s[i][2].t;
                    x=s[i][2].a;
                    break;
                }
            }

        }
        tim+=w[y];
        cout<<tim<<endl;
    }
    return 0;
}
