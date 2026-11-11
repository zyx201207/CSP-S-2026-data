#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[502],k,a[502][502],t[502][502],ans,x,y;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++)
    {
        cin>>k;
        for(long long j=i;j<k+i;j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(long long i=1;i<=q;i++)
    {
        cin>>x>>y;
        ans=w[x]+w[y];
        for(long long j=x;j<y;j++)
        {
            ans+=t[j][j]+t[j][j+1];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
