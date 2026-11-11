#include<bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>u[i]>>v[i];
        cout<<u[(n+k)/2]+v[abs(k-n)*6/8]*8/6<<endl;
    }
    return 0;
}
