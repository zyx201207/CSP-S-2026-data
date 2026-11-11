#include<bits/stdc++.h>
using namespace std;
int c,cc,p,pp;
string s,ss;
int main(void)
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>cc>>ss;
//    cout<<c<<" "<<s<<" "<<cc<<" "<<ss<<" ";
    for(int i=0;i<s.size()-1;i++)
    {
        p*=10;
        p+=s[i]-'0';
    }
    for(int i=0;i<ss.size()-1;i++)
    {
        pp*=10;
        pp+=ss[i]-'0';
    }
    //cout<<c<<" "<<s<<" "<<cc<<" "<<ss<<" "<<p<<" "<<pp<<" ";
    if(c==cc)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    if(c==cc && p==pp)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    if(c==cc && p==pp && ((s[2]<='C' && ss[2]<='C') || (s[2]>='D' && ss[2]>='D')))
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    if(c==cc && p==pp && ((s[2]<='C' && ss[2]<='C') || (s[2]>='D' && ss[2]>='D')) && abs(s[2]-ss[2])==1)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
