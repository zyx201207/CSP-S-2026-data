#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
        cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s1.size()!=s2.size())
    {
        cout<<"000";
        return 0;
    }
    for(int i=0;i<=s1.size()-2;i++)
    {
        if(s1[i]!=s2[i])
        {
            cout<<"000";
            return 0;
        }
    }
    cout<<1;
    char x1=s1[s1.size()-1];
    char x2=s2[s2.size()-1];
    if(x1=='A'||x1=='B'||x1=='C')
    {
        if(x2=='D'||x2=='F')
        {
            cout<<"00";
            return 0;
        }
        else
            cout<<1;
    }
    else
    {
        if(x2=='D'||x2=='F')
            cout<<1;
        else
        {
            cout<<"00";
            return 0;
        }
    }
    if(abs((x1-'0')-(x2-'0'))==1)
       cout<<1;
    else
        cout<<0;
    return 0;
}
