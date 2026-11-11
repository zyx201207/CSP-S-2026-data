#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN=500,MAXM=5e5;
int c,n,m,d,q,w[MAXM+5],k,a,t;
long long G[MAXN+5][MAXN+5];
struct id_val
{
    long long id,val;
};
vector<id_val>len[MAXM+5];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    memset(G,0x3f,sizeof(G));
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>t;
            len[a].push_back((id_val){i,t});
        }
        G[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<len[i].size();j++)
        {
            for(int k=0;k<len[i].size();k++)
                G[len[i][k].id][len[i][j].id]=G[len[i][j].id][len[i][k].id]=min(G[len[i][j].id][len[i][k].id],len[i][j].val+len[i][k].val);
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                G[j][i]=G[i][j]=min(G[i][j],G[i][k]+G[j][k]);
        }
    }
    while(q--)
    {
        cin>>a>>t;
        long long res=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<len[a].size();i++)
        {
            for(int j=0;j<len[t].size();j++)
                res=min(res,len[a][i].val+len[t][j].val+G[len[a][i].id][len[t][j].id]);
        }
        cout<<res+w[a]+w[t]<<endl;
    }
    return 0;
}
