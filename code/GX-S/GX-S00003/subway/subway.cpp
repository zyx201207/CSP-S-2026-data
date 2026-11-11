#include<bits/stdc++.h>
using namespace std;
struct b{
    long long tim,dt[20][2];
}d[500000+5];
long long a[500+5][500+5],dis[500+5][500+5];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dis,0x3f3f3f3f,sizeof dis);
    memset(a,0x3f3f3f3f,sizeof a);
	int c,n,m,f,q;
	cin>>c>>n>>m>>f>>q;
	for(int i=1;i<=m;++i)
        cin>>d[i].tim;
    for(int i=1;i<=n;++i)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;++j)
        {
            int t;
            cin>>t;
            cin>>d[t].dt[++d[t].dt[0][0]][1];
            d[t].dt[d[t].dt[0][0]][0]=i;
        }
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=2;j<=d[i].dt[0][0];++j)
        {
            for(int k=1;k<j;++k)
            {
                dis[d[i].dt[k][0]][d[i].dt[j][0]]=min(dis[d[i].dt[k][0]][d[i].dt[j][0]],d[i].dt[j][1]+d[i].dt[k][1]);
                dis[d[i].dt[j][0]][d[i].dt[k][0]]=dis[d[i].dt[k][0]][d[i].dt[j][0]];
            }
        }
    }
    for(int i=1;i<=n;++i)
            for(int j=i+1;j<=n;++j)
                a[i][j]=a[j][i]=min(a[i][j],dis[i][j]);
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=i+1;j<=n;++j)
                    a[i][j]=a[j][i]=min(a[i][j],a[i][k]+a[k][j]);
    for(int i=1;i<=n;++i)
        a[i][i]=0;
    while(q--)
    {
        int x,y;
        long long ans=1e18+9;
        cin>>x>>y;
        for(int i=1;i<=d[x].dt[0][0];++i)
            for(int j=1;j<=d[y].dt[0][0];++j)
                ans=min(a[d[x].dt[i][0]][d[y].dt[j][0]]+d[x].dt[i][1]+d[y].dt[j][1],ans);
        cout<<ans+d[x].tim+d[y].tim<< '\n';
    }
	return 0;
}
