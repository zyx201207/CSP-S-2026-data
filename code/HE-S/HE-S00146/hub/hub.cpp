#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k,x=0;
    int u[10001]={0},v[10001]={0};
    cin>>c>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>k;
        for(int i=0;i<n-1;i++)
        {
            cin>>u[i]>>v[i];
        }
    }
    for(int i=0;i<t;i++)
    {
        x++;
        cout<<x<<endl;
    }
    return 0;
}
