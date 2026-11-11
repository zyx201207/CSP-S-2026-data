#include<bits/stdc++.h>
using namespace std;
string z1,z2;
int a,b;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>z1>>b>>z2;
    if(a==b)
    {
        a=z1[0]+z1[1];
        b=z2[0]+z2[1];
        if(a==b)
        {
            if(z1[2]>='A'&&z1[2]<='C')
            {
                a=1;
            }
            else
            {
                a=2;
            }
            if(z2[2]>='A'&&z2[2]<='C')
            {
                b=1;
            }
            else
            {
                b=2;
            }
            if(a==b)
            {
                if(a==1)
                {
                    if(z1[2]=='A'&&z2[2]=='B')
                    {
                        cout<<1111;
                    }
                    else if(z1[2]=='B'&&z2[2]=='A')
                    {
                        cout<<1111;
                    }
                    else if(z1[2]=='B'&&z2[2]=='C')
                    {
                        cout<<1111;
                    }
                    else if(z1[2]=='C'&&z2[2]=='B')
                    {
                        cout<<1111;
                    }
                    else
                    {
                        cout<<1110;
                    }
                }
                else
                {
                    cout<<1111;
                }
            }
            else
            {
                cout<<1110;
            }
        }
        else
        {
            cout<<"1000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
