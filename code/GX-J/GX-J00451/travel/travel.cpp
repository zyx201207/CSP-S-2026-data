#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<0000;
    }
    else
    {
        if(int(s1[0])!=int(s2[0])||int(s1[1])!=int(s2[1]))
        {

            cout<<1000;
        }
        else if(s1[2]<='C'&&s2[2]>'C'||s2[2]<='C'&&s1[2]>'C')
        {
            cout<<1100;

        }
        else
        {
            if(abs(int(s2[2]-s1[2]))==1)
            {

                cout<<1111;
            }
            else
            {

                cout<<1110;
            }
        }
    }
    return 0;
}
