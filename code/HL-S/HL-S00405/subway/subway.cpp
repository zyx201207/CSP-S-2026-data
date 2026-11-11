#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+100;
int n,m,c,d,q,w[N];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int i=1;i<=k;i++)
        {

            int a,b;
            cin>>a>>b;
        }
    }
    while(q--)
    {

        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]<<endl;
    }
    return 0;
}
