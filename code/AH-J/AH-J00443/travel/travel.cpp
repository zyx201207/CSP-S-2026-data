#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int x1,x2,y1,y2;
    char z1,z2;
    x1=(int)c1[1]-48;
    x2=(int)c2[1]-48;
    y1=(int)s1[1]-48;
    y2=(int)s2[1]-48;
    if(c1[0]==49)
    {
        x1+=10;
    }
    if(c2[0]==49)
    {
        x2+=10;
    }
    if(s1[0]==49)
    {
        y1+=10;
    }
    if(s2[0]==49)
    {
        y2+=10;
    }
    z1=s1[2];
    z2=s2[2];
    if(x1==x2)
    {
        cout<<1;
        if(y1==y2)
        {
            cout<<1;
            if(z1>='A'&&z1<='C'&&z2>='A'&&z2<='C'||z1>='D'&&z1<='F'&&z2>='D'&&z2<='F')
            {
                cout<<1;
                int m=(int)z1-(int)z2;
                if(abs(m)==1)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
                return 0;
            }
            else
            {
                cout<<"00";
                return 0;
            }
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    else
    {
        cout<<"0000";
        return 0;
    }
}
