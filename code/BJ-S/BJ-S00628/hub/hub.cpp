#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,t;
const int maxN=1e6+10;
int u[maxN],v[maxN];

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int maxn=0;
        for(int i=1;i<n;i++)
        {
            cin>>u[i]>>v[i];
            maxn=max(maxn,abs(u[i]-v[i]));
        }
        cout<<maxn<<endl;
    }
    return 0;
}
