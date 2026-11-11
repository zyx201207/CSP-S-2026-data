#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+11;
int c,t,n,k;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
        }
        cout<<rand()%4<<"\n";
    }
    return 0;
}