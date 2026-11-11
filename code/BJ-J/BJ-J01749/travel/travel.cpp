#include<bits/stdc++.h>
using namespace std;
int x,y;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>s1>>y>>s2;
    if(x==y)
    {
        cout<<1;
    }
    else cout<<0;
    if(x==y&&s1[0]==s2[0]&&s1[1]==s2[1])
    {
        cout<<1;
    }
    else cout<<0;
    if(x==y&&s1[0]==s2[0]&&s1[1]==s2[1]&&(s1[2]-'A'<=2&&s2[2]-'A'<=2||s1[2]-'A'>2&&s2[2]-'A'>2))
    {
        cout<<1;
    }
    else cout<<0;
    if(x==y&&s1[0]==s2[0]&&s1[1]==s2[1]&&(s1[2]-'A'<=2&&s2[2]-'A'<=2||s1[2]-'A'>2&&s2[2]-'A'>2)&&(s1[2]==s2[2]+1||s2[2]==s1[2]+1))
    {
        cout<<1;
    }
    else cout<<0;
    return 0;
}
//1st csp! rp++