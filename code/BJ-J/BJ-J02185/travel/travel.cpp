#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int t1,t2;
    string s1,s2;
    cin>>t1>>s1;
    cin>>t2>>s2;
    if(t1==t2) cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])
        cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
    {
        if(s2[2]=='B'||s2[2]=='C')
        {
            cout<<1;
            if(abs((int)s1[2]-(int)s2[2])==1) cout<<1;
            else cout<<"0";
        }
        else cout<<"00";
    }
    else
    {
        if(s2[2]=='D'||s2[2]=='F')
        {
            cout<<1;
            if(abs((int)s1[2]-(int)s2[2])==2) cout<<1;
            else cout<<0;
        }
        else cout<<00;
    }
    return 0;
}
