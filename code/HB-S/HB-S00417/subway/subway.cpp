#include <bits/stdc++.h>
using namespace std;
long long change[505][505];
int in[500005];
int tim[500005][505];
vector<int>st[500005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >>m >> d >> q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            change[i][j]=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=m;i++)
        cin >> in[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        for(int j=1;j<=k;j++)
        {
            int a,b;
            cin >> a >> b;
            tim[a][i]=b;
            st[a].push_back(i);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<st[i].size()-1;j++)
        {
            for(int k=j+1;k<st[i].size();k++)
            {
                int x=st[i][j],y=st[i][k];
                int cnt=tim[i][x]+tim[i][y];
                if(cnt<change[x][y]) change[x][y]=change[y][x]=cnt;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        change[i][i]=0;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j || i==k || j==k) continue;
                if(change[i][k]+change[k][j]<change[i][j])
                    change[i][j]=change[i][k]+change[k][j];
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int l,r;
        long long minn=0x3f3f3f3f3f3f3f3f;
        cin >> l >> r;
        for(int i=0;i<st[l].size();i++)
        {
            for(int j=0;j<st[r].size();j++)
            {
                int x=st[l][i],y=st[r][j];
                if(minn>change[x][y]+in[l]+in[r]+tim[l][x]+tim[r][y])
                    minn=change[x][y]+in[l]+in[r]+tim[l][x]+tim[r][y];
            }
        }
        cout << minn << "\n";
    }
    return 0;
}
//O(n^3+q*d^2+m*d^2)
