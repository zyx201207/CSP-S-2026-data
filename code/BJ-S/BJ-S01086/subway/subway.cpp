#include<bits/stdc++.h>
using namespace std;
int w[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int t,c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x;
            cin>>x>>t;
        }
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<w[l]+w[r]+t*2<<"\n";
    }
    return 0;
}
