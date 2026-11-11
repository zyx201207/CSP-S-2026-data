#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c[2];
    string s;
    for(int i=0;i<2;i++)
    {
        string j;
        cin>>c[i]>>j;
        s+=j;
    }
    if(c[0]==c[1])
    {
        cout<<1;
    }
    else
        {
            cout<<0<<0<<0<<0;
            return 0;
        }
    if(s[0]==s[3]&&s[1]==s[4])
        cout<<1;
    else
        {
            cout<<0<<0<<0;
            return 0;
        }
    if(s[2]=='A'||s[2]=='B'||s[2]=='C'&&s[5]=='A'||s[5]=='B'||s[5]=='C'||s[2]=='D'||s[2]=='F'&&s[5]=='D'||s[5]=='F')
        cout<<1;
    else
    {
        cout<<0;
        cout<<0;
        return 0;
    }
    if(s[2]+1==s[5]||s[2]-1==s[5])
        cout<<1;
    else
        cout<<0;

    return 0;
}
