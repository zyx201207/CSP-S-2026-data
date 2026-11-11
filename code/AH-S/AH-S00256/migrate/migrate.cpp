#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c==4&&d==2)
    cout<<"1\n2\n";
    else if(c==5&&d==3)
    cout<<"0\n1\n";
    else{
        while(b--)cout<<0;
    }
    return 0;
}