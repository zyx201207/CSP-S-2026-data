
#include<bits/stdc++.h>
using namespace std;
string s[5];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i=0;i<=4;i++)
    {
        cin>>s[i];

    }
    for(int i=0;i<=4;i++)
    {
        if(s[1]==s[3])
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}
