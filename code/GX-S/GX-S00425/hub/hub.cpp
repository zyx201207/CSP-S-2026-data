#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t,c,n,k,x[1000100][1000100],a,b;
    cin>>c>>t;
    int sum=1;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b;
            x[a][b]=1;
            x[b][a]=1;
        }
        cout<<sum++;
    }
    return 0;
}
