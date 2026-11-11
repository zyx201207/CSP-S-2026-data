#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int flag=1;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<c1.size();i++)
    {
        if(c1[i]==c2[i])flag=1;
        else
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        cout<<1;
        int flag1=1;
        for(int i=0;i<s1.size()-1;i++)
        {
            if(s1[i]==s2[i])flag1=1;
            else
            {
                flag1=0;
                break;
            }
        }
        if(flag1==1)
        {
            cout<<1;
            if(s1[s1.size()-1]=='A' || s1[s1.size()-1]=='B' || s1[s1.size()-1]=='C')
            {
                if(s2[s2.size()-1]=='A' || s2[s2.size()-1]=='B' || s2[s2.size()-1]=='C')
                {
                    cout<<1;
                    if(s1[s1.size()-1]=='A')
                    {
                        if(s2[s2.size()-1]=='B')cout<<1;
                        else cout<<0;
                    }
                    if(s1[s1.size()-1]=='B')cout<<1;
                    if(s1[s1.size()-1]=='C')
                    {
                        if(s2[s2.size()-1]=='B')cout<<1;
                        else cout<<0;
                    }
                }
                else cout<<"00";
            }
            if(s1[s1.size()-1]=='D' || s1[s1.size()-1]=='F')
            {
                if(s2[s2.size()-1]=='D' || s2[s2.size()-1]=='F')cout<<"11";
                else cout<<"00";
            }
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
