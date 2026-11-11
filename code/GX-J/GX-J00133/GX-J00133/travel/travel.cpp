#include<iostream>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    bool f=1;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        f=0;
    }
    if(f==1)
    {
        for(int i=0;i<1;i++)
        {
            if((s1[i]==s2[i]&&s1[i+1]==s2[i+1])&&f==1)
            {
                cout<<"1";
            }
            else
            {
                cout<<"000";
                f=0;
            }
        }
    }
    if(f==1)
    {
        for(int i=2;i>1;i--)
        {
            if((s1[i]>='A'&&s1[i]<='C')&&(s2[i]>='A'&&s2[i]<='C'))
            {
                cout<<"1";
            }
            else if((s1[i]>='D'&&s1[i]<='F')&&(s2[i]>='D'&&s2[i]<='C'))
            {
                cout<<"1";
            }
            else
            {
                cout<<"00";
                f=0;
            }
        }
    }
    if(f==1)
    {
        for(int i=2;i>1;i--)
        {
            if((s1[i]=='A'&&s2[i]=='B')||(s1[i]=='B'&&s2[i]=='A')||(s1[i]=='B'&&s2[i]=='C')||(s1[i]=='C'&&s2[i]=='B'))
            {
                cout<<"1";
            }
            else if((s1[i]=='D'&&s2[i]=='F')||(s1[i]=='F'&&s2[i]=='D'))
            {
                cout<<"1";
            }
            else
            {
                cout<<"0";
            }
        }
    }
    return 0;
}
