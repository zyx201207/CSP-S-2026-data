#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int w[500005],k[505],x[100005],y[100005];
int o[500005];
int a[505][500005],t[505][500005];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(o,0x3f3f3f3f,sizeof(o));
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            o[a[i][j]]=min(o[a[i][j]],t[i][j]);
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
        long long sum=0;
        sum+=w[x[i]]+w[y[i]]+o[x[i]]+o[y[i]];
        cout<<sum<<endl;
    }
    return 0;
}
