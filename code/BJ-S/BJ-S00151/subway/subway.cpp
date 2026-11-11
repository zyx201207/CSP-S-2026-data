#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,w[500005],ans,sum,c,d,q;
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    
    for(int i=1;i<=n;i++)
        {cin>>w[i];sum+=w[i];}
    cout<<sum;
    return 0;
}
