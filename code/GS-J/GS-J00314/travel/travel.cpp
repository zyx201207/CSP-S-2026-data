#include<bits/stdc++.h>
using namespace std;

string c1,s1,c,s;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>c1>>s1;
    int a;

    string q,q1;
    char e,d;
    for(int i=0;i<2;i++)
    {

        q+=s[i];
        q1+=s1[i];

    }
    e=s[2];
    d=s1[2];
    if(c==c1)
    {
        cout<<1;
        if(q==q1)
        {
            cout<<1;
            if(e<='C'&&d<='C'||e>='D'&&d>='D')
            {
                cout<<1;
                a=int(e-d);
                if(abs(a)==1)
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
                cout<<"00";
            }
        }
        else
        {

            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
