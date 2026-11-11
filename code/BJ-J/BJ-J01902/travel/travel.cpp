#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(s1[2]=='D')
    {
        s1[2]='E';
    }
    if(s2[2]=='D')
    {
        s2[2]='E';
    }
    if(c1!=c2)
    {
        cout<<"0000";
    }
    else
    {
        cout<<1;
        if(s1.substr(0,2)!=s2.substr(0,2))
        {
            cout<<"000";
        }
        else
        {
            cout<<1;
            int pos1=s1[2]-'A',pos2=s2[2]-'A';
            if(pos1/3!=pos2/3)
            {
                cout<<"00";
            }
            else
            {
                cout<<1;
                if(abs(pos1-pos2)<=1)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
        }
    }
    return 0;
}
