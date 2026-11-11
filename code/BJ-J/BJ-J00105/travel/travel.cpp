#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)
    {
        cout<<1;
        if(a2[0]==b2[0]&&a2[1]==b2[1])
        {
            cout<<1;
            if((a2[2]<='C'&&b2[2]<='C')||(a2[2]>'C'&&b2[2]>'C'))
            {
                cout<<1;
                if(a2[2]==b2[2]+1||a2[2]+1==b2[2]||(a2[2]=='D'&&a2[2]=='F'))
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else
            {
                cout<<0<<0;
            }
        }
        else
        {
        cout<<0<<0<<0;
        }
    }
    else
    {
        cout<<0<<0<<0<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
