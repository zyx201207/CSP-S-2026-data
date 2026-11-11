#include<iostream>
#include<algorithm>
#include<list>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#define ENABLE_FLOYD 1
#define ENABLE_FLOYDA 1
#define test_is_A 0
using namespace std;
const int N=500005,N2=1005,M=505;
typedef long long ll;
int c,n,m,d,q;//nodecnt is m!
ll tmp[N];
//for floyd n^3
ll g2[N2][N2];
ll fst[M],fdst[M];
int main()
{
    //freopen("/home/rdfz/subway/subway4.in","r",stdin);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>tmp[i];
    if(((1<=c&&c<=8)||m+n<=600)&&ENABLE_FLOYD)
    {
        memset(g2,0x3f,sizeof g2);
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                int a;ll t;
                cin>>a>>t;
                g2[m+i][a]=t;
                g2[a][m+i]=t;
            }
        }
        for(int z=1;z<=m+n;z++)//floyd
            for(int i=1;i<=m+n;i++)
                for(int j=1;j<=m+n;j++)
                    g2[i][j]=min(g2[i][j],g2[i][z]+g2[z][j]);
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            cout<<g2[x][y]+tmp[x]+tmp[y]<<'\n';
        }
    }
    else if(((7<=c&&c<=11)||test_is_A)&&ENABLE_FLOYDA)
    {
        memset(g2,0x3f,sizeof g2);
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                int a;ll t;
                cin>>a>>t;
                if(j==1) fst[i]=a,fdst[i]=t;
                else
                {
                    g2[fst[i]][a]=t+fdst[i];
                    g2[a][fst[i]]=t+fdst[i];
                }
            }
        }
        for(int z=1;z<=m;z++)//floyd
            for(int i=1;i<=m;i++)
                for(int j=1;j<=m;j++)
                    g2[i][j]=min(g2[i][j],g2[i][z]+g2[z][j]);
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            cout<<g2[x][y]+tmp[x]+tmp[y]<<'\n';
        }
    }
    cout.flush();
    return 0;
}
