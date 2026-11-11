#include<bits/stdc++.h>
using namespace std;

string s;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    getline(cin,s);
    if(s[0]==s[7]&&s[1]==s[8])
    {
        cout<<"1";
        if(s[3]==s[10]&&s[4]==s[11])
        {
            cout<<"1";
            if(s[5]-'A'<=2&&s[12]-'A'<=2||s[5]-'A'>=3&&s[12]-'A'>=3)
            {
                cout<<"1";
                if(abs(s[5]-s[12])==1)
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
