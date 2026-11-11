#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c1,c2;
    string s1,s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        string ss1="",ss2="";
        char x1=s1[2],x2=s2[2];
        ss1+=s1[0];
        ss1+=s1[1];
        ss2+=s2[0];
        ss2+=s2[1];
        if(ss1==ss2)
        {
            cout<<1;
            if('A'<=x1&&x1<='C'&&'A'<=x2&&x2<='C'||x1=='D'&&x2=='F'||x1=='F'&&x2=='D')
            {
                cout<<1;
                if(x1=='A'&&x2=='B'||x1=='B'&&x2=='A'||x1=='B'&&x2=='C'||x1=='C'&&x2=='B'||x1=='D'&&x2=='F'||x1=='F'&&x2=='D')
                {
                    cout<<1;
                }
                else cout<<0;
            }
            else
            {
                cout<<0;
                cout<<0;
            }
        }
        else
        {
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }
    else
    {
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }

}
