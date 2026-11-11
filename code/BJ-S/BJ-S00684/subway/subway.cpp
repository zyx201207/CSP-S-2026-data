#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
using namespace std;

struct node
{
    int u,v,l;
};

int w[500010];
int f[500010];
int a[500010];
int t[500010];
vector<node> g;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++)cin>>w[i];

    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;

        for(int j=1;j<=k;j++)
        {
            cin>>a[j]>>t[j];

            for(int x=1;x<j;x++)
            {
                g.push_back({a[j],a[x],t[j]+t[x]});
                g.push_back({a[x],a[j],t[x]+t[j]});
            }
        }
    }

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        memset(f,0x3f,sizeof(f));
        f[l]=0;
        while(true)
        {
            bool flag=true;
            for(int i=0;i<g.size();i++)
            {
                node line=g[i];

                if(f[line.v]>f[line.u]+line.l)
                {
                    f[line.v]=f[line.u]+line.l;
                    flag=false;
                }
            }

            if(flag)break;
        }

        cout<<f[r]+w[l]+w[r]<<endl;
    }
    return 0;
}
