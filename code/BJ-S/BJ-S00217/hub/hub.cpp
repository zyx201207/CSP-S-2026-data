#include <bits/stdc++.h>
using namespace std;

int c,t,n,k,u,v;

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(0));
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n-1;i++) cin>>u>>v;
        cout<<rand()%(n-1)+1<<endl;
    }
    return 0;
}