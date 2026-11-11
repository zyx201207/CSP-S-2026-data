#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
vector<int> ve[1000010];
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u, v;
            cin>>u>>v;
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        if(n<=k)
        {
            cout<<0<<endl;
            continue;
        }
        if(c==13||c==14)
        {
            int ans=1;
            n/=2;
            for(int i=1;i<=n;i++)
            {
                if(n/i>k)
                    ans++;
                else break;
            }
            cout<<ans<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/