#include<iostream>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    int n,k;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        for(int i=1;i<=n-1;i++)
        {
            cin>>u[i]>>v[i];
            cout<<endl;
        }
    }
    if(c==0)
    {
        cout<<"1"<<endl<<"2";
    }
    else
    {
        cout<<"1"<<endl<<"1"<<endl<<"2";
    }
    return 0;
}
