#include <bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char side1,side2;
int ans;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1;
    cin>>s1;
    cin>>side1;
    cin>>c2;
    cin>>s2;
    cin>>side2;
    if(c1==c2)
    {
        cout<<"1";
        if(s1==s2)
        {
            cout<<"1";
            if(side1=='D')
        {
            if(side2=='F')
                cout<<"1";
            else
                cout<<"0";
        }
        else if(side2=='D')
        {
            if(side1=='F')
                cout<<"1";
            else
                cout<<"0";
        }
        else
        {
            if(side2=='F'||side1=='F')
                cout<<"0";
            else
                cout<<"1";
        }
        //special,next to
        if(side1=='D'||side2=='D')
        {
            if(side1=='D')
            {
                if(side2!='F')
                    cout<<"0";
                else
                    cout<<"1";
            }
            else if(side2=='D')
            {
                if(side1!='F')
                    cout<<"0";
                else
                    cout<<"1";
            }
        }
        else //3 side
        {
            if(side1=='A'&&side2=='B')
                cout<<"1";
            else if(side1=='B'&&side2=='A')
                cout<<"1";
            else if(side1=='B'&&side2=='C')
                cout<<"1";
            else if(side1=='C'&&side2=='B')
                cout<<"1";
            else
                cout<<"0";
        }
        }
        else
        cout<<"000";
    }
    else
        cout<<"0000";


    return 0;
}

