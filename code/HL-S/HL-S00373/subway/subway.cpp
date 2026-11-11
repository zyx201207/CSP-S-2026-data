#include<iostream>
using namespace std;
long long c,n,m,d,q,w[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway,out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
        for(int i=1;i<=m;i++)
        {
            cin>>w[i];
        }
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]<<'\n';
        }

    return 0;
}
