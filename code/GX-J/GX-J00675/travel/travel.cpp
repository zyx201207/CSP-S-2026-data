#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int n1,n2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    n1=s1[0]+s1[1];
    n2=s2[0]+s2[1];
    s1=s1[2];
    s2=s2[2];
    if(c1==c1)
    {
        cout<<"1";
        if(n1==n2)
        {
            cout<<"1";
            if(((s1=="A"||s1=="B"||s1=="C")&&(s2=="A"||s2=="B"||s2=="C"))||((s1=="D"||s1=="F")&&(s2=="D"||s2=="F")))
            {
                cout<<"1";
                if(s1=="B"||s2=="B"||s1=="D"||s2=="D")
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
