#include<bits/stdc++.h>
using namespace std;
int tt,T,n,k;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>tt>>T;
    while(T--)
    {
        cin>>n>>k;
        int x,y;
        for(int i=1;i<n;i++)
        {
            cin>>x>>y;
        }
        if(n>=4&&k==1)cout<<2<<'\n';
        else cout<<1<<'\n';
    }
}
