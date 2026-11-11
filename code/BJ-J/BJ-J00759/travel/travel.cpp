#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char s12,s22;
bool flag1,flag2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2?1:0);
    if(!(c1==c2))
    {
        cout<<"000";
        return 0;
    }
    cout<<(s1[0]==s2[0]&&s1[1]==s2[1]?1:0);
    if(!(s1[0]==s2[0]&&s1[1]==s2[1]))
    {
        cout<<"00";
        return 0;
    }
    s12=s1[2],s22=s2[2];
    if(s12=='A'||s12=='B'||s12=='C') flag1=true;
    if(s22=='A'||s22=='B'||s22=='C') flag2=true;
    cout<<(flag1==flag2?1:0);
    if((s12=='A'&&s22=='B')||(s12=='B'&&s22=='A')||(s12=='C'&&s22=='B')||(s12=='B'&&s22=='C')||(s12=='D'&&s22=='F')||(s12=='F'&&s22=='D')) cout<<1;
    else cout<<0;
    return 0;
}