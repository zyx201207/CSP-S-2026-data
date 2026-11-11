#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            dist[i-1]=x[i]-x[i-1];
        }
        int a=d/dist[1];
        if(a<2)cout<<"0\n";
        else cout<<max(0,n-2*a+1)<<'\n'
    }
}
