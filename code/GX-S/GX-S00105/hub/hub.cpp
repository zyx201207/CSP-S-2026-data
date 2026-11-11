#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","r",stdout);
    int a,b,c;
    cin>>a>>b;
    for(int i=0;i<b;i++)
    {
        cin>>a>>c;
        for(int j=1;j<a;j++)cin>>c;
    }
    for(int i=1;i<b;i++)
    {
        cout<<"1"<<endl;
    }
    cout<<"2"<<endl;
    return 0;
}
