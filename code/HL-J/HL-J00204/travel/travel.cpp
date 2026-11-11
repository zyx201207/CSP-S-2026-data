#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool flag=1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) flag=1;
    else flag=0;
    cout<<flag;
    if(flag==0)
    {
        cout<<"000";
        return 0;
    }



    if(s1[0]==s2[0] && s1[1]==s2[1]) flag=1;
    else flag=0;
    cout<<flag;
    if(flag==0)
    {
        cout<<"00";
        return 0;
    }
    char ch1=s1[2],ch2=s2[2];



    if(ch1=='A' || ch1=='B' || ch1=='C')
    {
        if(ch2=='A' || ch2=='B' || ch2=='C')
        {

            flag=1;
        }
        else flag=0;
    }
    else
    {

        if(ch2=='D' || ch2=='F')
        {

            flag=1;
        }
        else flag=0;
    }
    cout<<flag;
    if(flag==0)
    {
        cout<<"0";
        return 0;
    }

    if(abs(ch1-ch2) || (ch1=='D' && ch2=='F') || (ch1=='F' && ch2=='D'))
    {
        flag=1;
    }
    else flag=0;
    cout<<flag;
    return 0;
}

