#include<bits/stdc++.h>
using namespace std;
int n,k,u,v,ans=0,c,t;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>u>>v;
        if(n==k) cout<<0;
        else cout<<max((n/2-k+2)/4+((n/2-k+2/4)%4?1:0),1);
        cout<<'\n';
    }
    return 0;
}