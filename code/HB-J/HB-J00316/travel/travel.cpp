#include<bits/stdc++.h>
using namespace std;
bool same(string s1,string s2)
{
    if(s1.size()!=s2.size())
    return false;
    for(int i=0;i<s1.size();i++)
        if(s1[i]!=s2[i])
            return false;
    return true;
}
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string s1,c1,s2,c2;
cin>>c1>>s1>>c2>>s2;
if(same(c1,c2))
{
    cout<<"1";
    string ss1=s1.substr(0,2);
    string ss2=s2.substr(0,2);
    if(same(ss1,ss2))
    {
        cout<<"1";
        char cr1=s1[s1.size()-1],cr2=s2[s2.size()-1];
        if(cr2>cr1)
        {
            swap(cr2,cr1);
        }
        if((cr2=='A'||cr2=='B'||cr2=='C')&&(cr1=='D'||cr1=='F'))
        {
            cout<<"00";
        }
        else
        {
            cout<<"1";
            int ic1=int(cr1),ic2=int(cr2);
            if(sqrt(ic1-ic2)==1)
            {
                cout<<"1";
            }
            else
            {
                cout<<"0";
            }
        }
    }
    else
    {
        cout<<"000";
    }
}
else
    cout<<"0000";

return 0;
}
