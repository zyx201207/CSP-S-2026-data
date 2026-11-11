#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,c1,s1;
    cin>>c>>s>>c1>>s1;
    if(c==c1)
        cout<<1;
    else
        cout<<0;
    if(c==c1&&s[0]==s1[0]&&s[1]==s1[1])
        cout<<1;
    else
        cout<<0;
    if(s[2]=='C'&&s1[2]=='D')
        cout<<0;
    else
    {
        if(c==c1&&s[0]==s1[0]&&s[1]==s1[1])
            cout<<1;
    }
    if(s[2]+1==s1[2]||s[2]-1==s1[2])
        cout<<1;
    else
        cout<<0;
    return 0;
}
