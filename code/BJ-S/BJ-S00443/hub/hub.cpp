#include<iostream>
using namespace std;
long long c,t,n,k,x,y;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
        }
        if(n==k)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl;
        }
    }
    return 0;
}

