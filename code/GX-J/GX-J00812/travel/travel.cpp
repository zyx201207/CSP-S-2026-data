#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string S1,S2;
    int s1=0,s2=0,c1=0,c2=0;
    char s1c,s2c;
    cin>>c1>>S1>>c2>>S2;
    for(int i=0;i<S1.size();i++)
    {
        if(S1[i]>'0'&&S1[i]<='9')
            s1=s1*10+(S1[i]-'0');
        if(i==2)
            s1c=S1[i];
    }
    for(int i=0;i<S2.size();i++)
    {
        if(S2[i]>'0'&&S2[i]<='9')
            s2=s2*10+(S2[i]-'0');
        if(i==2)
            s2c=S2[i];
    }
    if(c1==c2)
    {
        cout<<1;
        if(s1==s2)
        {
            cout<<1;
            if((s1c>='A'&&s1c<='C'&&s2c>='A'&&s2c<='C')||(s1c>='D'&&s1c<='F'&&s2c>='D'&&s2c<='F'))
            {
                cout<<1;
                if(abs(s1c-s2c)==1)
                    cout<<1;
                else
                    cout<<0;
            }

            else
                cout<<"00";
        }
        else
        {
            cout<<"000";
        }
    }
    else
        cout<<"0000";
    return 0;
}
