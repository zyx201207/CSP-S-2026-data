#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500050];
struct nod
{
    int to;
    int nxt;
    int tim;
};
nod b1[500050];
int h1[500050];
int cnt1;
int b[505][505];
inline void ccc1(int x,int y,int z)
{
    ++cnt1;
    b1[cnt1].to=y;
    b1[cnt1].nxt=h1[x];
    h1[x]=cnt1;
    b1[cnt1].tim=z;
    return ;
}
void clxl()
{
    int i,j;
    int d;
    int dd;
    d=1;
    while(d<=m)
        {
            i=h1[d];
            while(i!=-1)
                {
                    j=h1[d];
                    while(j!=-1)
                        {
                            if(b1[i].to!=b1[j].to)b[b1[i].to][b1[j].to]=min(b[b1[i].to][b1[j].to],b1[i].tim+b1[j].tim);
                            j=b1[j].nxt;
                        }
                    i=b1[i].nxt;
                }
            ++d;
        }
    return ;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(h1,-1,sizeof(h1));
    memset(b,63,sizeof(b));
    cin>>c>>n>>m>>d>>q;
    int i,j;
    i=1;
    while(i<=m)
        {
            cin>>w[i];
            ++i;
        }
    int k;
    int x,y;
    i=1;
    while(i<=n)
        {
            cin>>k;
            j=1;
            while(j<=k)
                {
                    cin>>x>>y;
                    ccc1(x,i,y);
                    ++j;
                }
            ++i;
        }
    clxl();
    i=1;
    while(i<=n)
        {
            b[i][i]=0;
            ++i;
        }
    i=1;
    while(i<=n)
        {
            j=1;
            while(j<=n)
                {
                    if(j==i)
                        {
                            ++j;
                            continue;
                        }
                    k=1;
                    while(k<=n)
                        {
                            if(k==i||k==j)
                                {
                                    ++k;
                                    continue;
                                }
                            b[j][k]=min(b[j][k],b[j][i]+b[i][k]);
                            ++k;
                        }
                    ++j;
                }
            ++i;
        }
    // cout<<'!';
    k=1;
    int ans;
    while(k<=q)
        {
            cin>>x>>y;
            ans=1e18+100;
            i=h1[x];
            while(i!=-1)
                {
                    j=h1[y];
                    while(j!=-1)
                        {
                            ans=min(ans,b[b1[i].to][b1[j].to]+b1[i].tim+b1[j].tim);
                            j=b1[j].nxt;
                        }
                    i=b1[i].nxt;
                }
            ans+=w[x]+w[y];
            cout<<ans<<'\n';
            ++k;
        }
    return 0;
}