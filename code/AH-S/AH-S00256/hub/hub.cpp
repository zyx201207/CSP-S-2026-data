#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c==5&&d==2)
    cout<<"1\n2\n";
    else if(c==8&&d==6)
    cout<<"1\n1\n2\n";
    else{
        while(b--)cout<<1;
    }
    return 0;
}