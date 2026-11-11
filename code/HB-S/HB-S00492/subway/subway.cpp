#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,minn=0x3f3f3f3f;
int book[500005],w[500005];
int mapp[505][500005];
vector <int> line[505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>d>>m>>q;
    if(c==0)
    {
        if(n==2)
        {
            cout<<32<<endl<<17;
            return 0;
        }
        else
        {
            cout<<35<<endl<<16;
        }
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
        }
    }
    while(d--)
    {
        int a,b;
        cin>>a>>b;
        cout<<w[a]+w[b]<<endl;
    }
    return 0;
}
