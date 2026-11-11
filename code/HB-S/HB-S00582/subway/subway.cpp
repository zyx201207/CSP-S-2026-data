#include <iostream>
#include <vector>
#define int long long
using namespace std;
const int N=1e6+5,MX=1e16;
int dis[505][505];
vector <int> a[N/2],t[N/2];
int n,m,d,q,c;
int w[N];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
    {
        int K;
        scanf("%lld",&K);
        for(int j=1;j<=K;j++)
        {
            int AAA,BBB;
            scanf("%lld%lld",&AAA,&BBB);
            a[AAA].push_back(i);
            t[AAA].push_back(BBB);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)dis[i][j]=MX;
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        int j=i;
        for(int k=0;k<a[i].size();k++)
        {

            for(int p=0;p<a[j].size();p++)
            {
                
                dis[a[i][k]][a[j][p]]=min(dis[a[i][k]][a[j][p]],t[i][k]+t[j][p]);
                dis[a[j][p]][a[i][k]]=min(dis[a[j][p]][a[i][k]],t[i][k]+t[j][p]);
                    
            }
        }
        
    }
    /*cout<<a[2].size()<<endl;
    cout<<t[2][0]<<" "<<t[2][1]<<endl;
    cout<<dis[1][2]<<" ";*/
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int _u,_v,ans=MX;
        scanf("%lld%lld",&_u,&_v);
        for(int j=0;j<a[_u].size();j++)
        {
            for(int k=0;k<a[_v].size();k++)//
            {
                
                ans=min(ans,dis[a[_u][j]][a[_v][k]]+t[_u][j]+t[_v][k]);
                
            }
        }
        printf("%lld\n",ans+w[_u]+w[_v]);
    }
    return 0;
}
/*

g++ subway.cpp -O0 -g -o subway -std=c++14
gdb -q -tui ./subway
b 52
r
disp dis[1][0]@5

diff subway.out subway7.ans
*/