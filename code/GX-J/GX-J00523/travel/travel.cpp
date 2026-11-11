#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>s1>>c1>>s2>>c2;
    for(int i=0;i<17;i++)
    {
        cin>>s1[i];
        cin>>s2[i];
        if(s1[i]==s2[i])
        {
            cout<<"1";
        }
        else
        {
          cout<<"0";

        }

    }

    for(int i=1;i<=18;i++)
    {
        for(int i=1;i<=5)
        {
           cin>>c1[i]>>c2[i];
           if(c1[i]==c2[i] || c1[3]!=c2[4])
           {
               cout<<"1";
           }
            else{
                cout<<"0";
            }
        }

    }
    if(s1[i]==s2[i] && c1[i+1]=c2[i])
    {
        cout<<"1111";
    }
    else if(s1[i]!=s2[i] && c1[i+1]!=c2[i])
    {
        cout<<"0000";
    }
    return 0;
}
