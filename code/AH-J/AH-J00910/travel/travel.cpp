#include <iostream>
#include <string>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(b[0]==d[0]&&b[1]==d[1])
    {
        cout<<"1";
        if((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
        {
            cout<<1;
            break;
        }

        if((c[2]=='D'||c[2]=='F')&&(d[2]=='D'||d[2]=='F'))
        {
            cout<<1;
            break;
        }
    }
    else
    {
        cout<<0;
    }
    cout<<1;
    return 0;
}
