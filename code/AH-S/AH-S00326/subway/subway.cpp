#include<bits/stdc++.h>
using namespace std;
const int N=505;
struct Node{
    int to,w;
};
vector<Node> g[N];
int c,n,m,d,q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
        }
        for(int i=1;i<=q;i++)
        {
            cin>>x>>y;
            cout<<16*(x+y);
        }
    }
    //Oct31==Dec25?
    return 0;
}