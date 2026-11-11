#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int a,v;
}f[1000][1000];
struct n{
    int xx,yy,kk;
}r[1000100];
int c,n,m,k[1000100],d,q,w[1000100],z[1000100],op;
node dd[1000100];

int cmp(node x,node y)
{
    return x.a<y.a;
}
int x,y;
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>f[i][j].a>>f[i][j].v;
            dd[++op].a=f[i][j].a;
            dd[op].v=i;
        }
    }
    int oq=0;
    sort(dd+1,dd+op+1,cmp);
    for(int i=1;i<=op;i++)
    {
        if(dd[i].a==dd[i-1].a)
        {
            r[++oq].xx=dd[i].v;
            r[oq].yy=dd[i-1].v;
            r[oq].kk=dd[i].a;
        }
    }
    int s1=0,s2=0,z=0;
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        for(int j=1;j<=n;j++)
        {

            for(int oo=1;oo<=k[j];oo++)
            {
                if(f[j][oo].a==x)
                {
                    s1=k[j];
                }
                if(f[j][oo].a==y)
                {

                    s2=k[j];
                }
                if(s1!=0&&s2!=0) break;
            }
        }
        z+=w[x]+w[y];
        for(int j=1;j<=oq;j++)
        {
                z+=f[s1][r[j].kk].v+f[s2][r[j].kk].v;
                cout<<z;
        }
    }
    return 0;
}
