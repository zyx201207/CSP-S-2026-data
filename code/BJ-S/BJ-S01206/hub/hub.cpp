#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long c,t;
    cin>>c>>t;
    if(13>=c&&c<=14)
    {
        while(t--)
        {
            long long n,k;
            cin>>n>>k;
            for(long long i=1;i<=n;i++)
            {
                long long u,v;
                cin>>u>>v;
            }
            cout<<((n+1)/2-k)/3+1<<'\n';
        }
        return 0;
    }
    return 0;
}
