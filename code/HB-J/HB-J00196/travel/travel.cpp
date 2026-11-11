#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c,c1;
    string s,s1;
    cin>>c>>s>>c1>>s1;
    if(c==c1)
    {
        cout<<1;
        if(s[0]==s1[0]&&s[1]==s1[1])
        {
            cout<<1;
            if(s[2]<='C'&&s1[2]<='C'||s[2]>='D'&&s1[2]>='D')
            {
                cout<<1;
                if(s[2]==s1[2]+1&&s1[2]!='C'||s[2]==s1[2]-1&&s1[2]!='D')
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
    return 0;
}
