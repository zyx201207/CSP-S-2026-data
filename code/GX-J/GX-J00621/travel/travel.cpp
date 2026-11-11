#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string e="";
    e+=b[0];
    e+=b[1];
    string f="";
    f+=d[0];
    f+=d[1];
    if(a==c)
    {
        cout<<"1";
        if(e==f)
        {
            cout<<1;
            string s="",l="";
            s=b[2];
            l=d[2];
            if((s=="D"&&l=="F")||(s=="F"&&l=="D"))
            {
                cout<<"11";
            }
            else if(s>="A"&&l<="C")
            {
                cout<<1;
                if(s=="A"&&l=="B")
                {
                    cout<<1;
                }
                else if(s=="B"&&l=="A")
                {
                    cout<<1;
                }
                else if(s=="B"&&l=="C")
                {
                    cout<<1;
                }
                else if(s=="C"&&l=="B")
                {
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
