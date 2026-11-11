#include<bits/stdc++.h>
using namespace std;
int m,n,c,d,q;
long long w[500005];
long long ta[500][500];
long long x[500005],y[500005];
int main()
{
    freopen("subway.in","w",stdin);
    freopen("subway.out","r",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ta[i][j];
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>x[i]>>y[i];
    }
    return 0;
}
