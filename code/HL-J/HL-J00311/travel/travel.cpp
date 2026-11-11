#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool d=false;
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int n=s1.size(),m=s2.size();
    if(n!=m)
    {
        cout<<"0000";
        d=true;
    }
    if(d=false)
    {
        if(n==3)
        {
            if((c1[2]!=c2[2])||c1[1]!=c2[1])
            {
                cout<<"0000";
                d=true;
            }
        }
        else
        {
            if(c1[1]!=c2[1])
            {
                cout<<"0000";
                d=true;
            }
        }
    }
    if(d==false)
    {
        cout<<"1";
        if((s1[1]!=s2[1])||(s1[0]!=s2[0]))
        {
            cout<<"000";
        }
        else
        {
            cout<<"1";
            if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')))
            {
                cout<<"1";
                if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))
                {
                    cout<<"0";
                }
                else if((s1[2]=='C'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='C'))
                {
                    cout<<"0";
                }
                else if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))
                {
                    cout<<"0";
                }
                else if((s1[2]=='A'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='A'))
                {
                    cout<<"0";
                }
                else if((s1[2]=='A'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='A'))
                {
                    cout<<"0";
                }
                else if((s1[2]=='B'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='B'))
                {
                    cout<<"0";
                }
                else if((s1[2]=='B'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='B'))
                {
                    cout<<"0";
                }
                else
                {
                    cout<<"1";
                }
            }
            else
            {
                cout<<"00";
            }
        }
    }
    return 0;
}
