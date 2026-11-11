#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w".stdout);
    string c;
    string s;
    string a;
    string b;
    cin>>c>>s>>a>>b;
    if(c.size()==a.size())
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    if(c.size()==a.size && s.size(2)==b.size(2))
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    if(c.size()==a.size && s.size(2)==b.size(2) && (s.size(3)=="A" || s.size(3)=="B" || s.size(3)=="C") && (b.size(3)=="A" || b.size(3)=="B" || b.size(3)=="C"))
    {
        cout<<"1";
    }
    else if(c.size()==a.size && s.size(2)==b.size(2) && (s.size(3)=="D" || s.size(3)=="F") && (b.size(3)=="D" || b.size(3)=="F"))
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    if(c.size()==a.size && s.size(2)==b.size(2) && (s.size(3)=="A" || s.size(3)=="B" || s.size(3)=="C") && (b.size(3)=="A" || b.size(3)=="B" || b.size(3)=="C") && (s.size(3)=="A" && b.size(3)=="B") || (s.size(3)=="B" && b.size(3)=="A") || (s.size(3)=="B" && b.size(3)=="C") || (s.size(3)=="B" && b.size(3)=="C") || (s.size(3)=="D" && b.size(3)=="F") || (s.size(3)=="F" && b.size(3)=="D"))
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
