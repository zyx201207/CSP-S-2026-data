#include <bits/stdc++.h>
using namespace std;
int c1,c2;
bool wen1,wen2,wen3;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2)
    {
        cout<<1;
        wen1=1;
    }
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    int a=(s1[0]-'0')*10+(s1[1]-'0');
    int b=(s2[0]-'0')*10+(s2[1]-'0');
    if (wen1&&a==b)
    {
        cout<<1;
        wen2=1;
    }
    else cout<<0;
    if (wen1&&wen2)
    {
        if (s1[2]=='C'&&s2[2]=='D')
        {
            cout<<0;
        }
        else if (s2[2]=='C'&&s1[2]=='D')
        {
            cout<<0;
        }
        else
        {
            cout<<1;
            wen3=1;
        }


    }
    else cout<<0;
    if (wen3&&abs((s1[2]-'0')-(s2[2]-'0'))==1)
    {
        cout<<1;
    }
    else if (s1[2]=='D'||s2[2]=='D') cout<<1;
    else cout<<0;
}
