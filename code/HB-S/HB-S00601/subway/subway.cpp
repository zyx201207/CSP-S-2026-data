#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5,N=505;
int c,n,m,d,q,w[M];
vector<int>a[N],t[N];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=1;j<=x;j++)
        {
            int y,z;
            cin>>y>>z;
            a[i].push_back(y);
            t[i].push_back(z);
        }
    }
    while(q--)
    {
        int x,y,ans=0;
        cin>>x>>y;
        for(int i=1;i<=n;i++)
            for(int j=0;j<a[i].size();j++)
                if(a[i][j]==x)
                    for(int k=0;k<a[i].size();k++)
                        if(a[i][k]==y)
                        {
                            ans=w[x]+w[y]+t[i][x]+t[i][y];
                            goto X;
                        }
        X:cout<<ans<<'\n';
    }
    return 0;
}
