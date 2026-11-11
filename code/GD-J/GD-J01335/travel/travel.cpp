#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;
int n1,n2;
char w1,w2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    w1=s1[2];
    w2=s2[2];
    n1=((char)s1[0]-'0')*10+(char)s1[1]-'0';
    n2=((char)s2[0]-'0')*10+(char)s2[1]-'0';
    //cout<<n1<<' '<<n2<<' '<<w1<<' '<<w2<<endl;
    if(n1==n2)
    {
        cout<<"1";
        //cout<<"io";
        if(((w1>='A'&&w1<='C')&&(w2>='A'&&w2<='C'))||((w1>='D'&&w1<='F')&&(w2>='D'&&w2<='F')))
        {
            //cout<<"no";
            cout<<"1";
            if(w1-1==w2||w1+1==w2)
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

    return 0;
}
