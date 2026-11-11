#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    string c1,c2;
    char s11,s21;
    int s12,s22;
    bool ce1,ce2,a=0;
    cin>>c1>>s12>>s11>>c2>>s22>>s21;
    if(c1==c2)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
        cout<<"0";
        cout<<"0";
        cout<<"0";
        return 0;
    }
    if(s12==s22)
    {
        cout<<"1";
        if(s11=='A'||s11=='B'||s11=='C')
        {
            ce1=0;
        }
        else if(s21=='F'||s21=='D')
        {
            cout<<"1";
        }
        if(s21=='A'||s21=='B'||s21=='C')
        {
            ce2=0;
        }
        else if(s21=='F'||s21=='D')
        {
            ce2=1;
        }
         if(ce1!=ce2)
        {

            cout<<"0";
            cout<<"0";
            return 0;
        }
        if(ce2==ce1)
        {

            cout<<"1";
            if(s11=='A')
            {
                if(s21=='B')
                {
                    a=1;
                    cout<<"1";
                }
            }
            else if(s11=='B')
            {
                if(s21=='A'||s21=='C')
                {
                    a=1;
                    cout<<"1";
                }
            }
            else if(s11=='C')
            {
                if(s21=='B')
                {
                    a=1;
                    cout<<"1";
                }
            }
            else if(s11=='D')
            {
                if(s21=='F')
                {
                    a=1;
                    cout<<"1";
                }
            }
            else if(s11=='F')
            {
                if(s21=='D')
                {
                    a=1;
                    cout<<"1";
                }
            }
            else if(a==false)
            {

                cout<<"0";
            }
        }
    }
    if(s12!=s22)
        cout<<"0";
        cout<<"0";
        cout<<"0";
        return 0;
    return 0;
}
