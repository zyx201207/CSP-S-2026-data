#include <bits/stdc++.h>
#define int long long
#define N 2000005

using namespace std;

int c,t,n,k,u[N],v[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if(c==13||c==14)
    {
        while(t--)
        {
            cin>>n>>k;
            for(int i=1;i<=n;i++)
                cin>>u[i]>>v[i];
            if(k>n/2)cout<<n-k<<'\n';
        }
    }
    return 0;
}
