#include <bits/stdc++.h>
using namespace std;
int t_ktt[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>t_ktt[i];
    }
    int a[n+5][m+5],t[n+5][m+5];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        int start,close;
        cin>>start>>close;
        cout<<t[start][1]+t[close][i];
    }

    return 0;
}
