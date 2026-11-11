#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,l,tm;
int a[500009],r[100009][2];
long long x[509][509],y[509][509];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << noboolalpha;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>l;
        for(int j=0;j<l;j++)
        {
            cin>>x[i][j]>>y[i][j];
        }
    }
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>r[i][j];
        }
    }
    for(int i=0;i<q;i++)
    {
        cout<<a[r[i][0]-1]+a[r[i][1]-1]+y[0][0]+y[0][1]+y[1][0]+y[1][01]<<'\n';
    }
    return 0;
}
