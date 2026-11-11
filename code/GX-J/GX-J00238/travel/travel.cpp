#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s;
    string ans("0000");
    getline(cin,s);
    if(s[0]+s[1]==s[7]+s[8])
    {
        ans[0]='1';
        if(s[3]+s[4]==s[10]+s[11])
        {
            ans[1]='1';
            if((s[5]<='C'&&s[12]<='C')||(s[5]>'C'&&s[12]>'C'))
            {
                ans[2]='1';
                bool flag=false;
                if((s[5]<='C'&&s[12]<='C'))
                    flag=true;
                if((flag&&abs(s[5]-s[12])==1)||(!flag))
                {
                    ans[3]='1';
                }
                cout<<ans;
            }
            else
            {
                cout<<ans;
            }
        }
        else
        {
            cout<<ans;
        }
    }
    else
    {
        cout<<ans;
    }
    return 0;
}
