#include<iostream>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int c[4]={0},s[4]={0};
    c[1]+=c1[0]*10;
    c[1]+=c1[1];
    c[2]+=c2[0]*10;
    c[2]+=c2[1];
    if(c[1]!=c[2])
    {
        cout<<"0000";
    }
    else
    {
        cout<<"1";
        s[1]+=s1[0]*10;
        s[1]+=s1[1];
        s[2]+=s2[0]*10;
        s[2]+=s2[1];
        if(s[1]!=s[2])
        {
            cout<<"000";
        }
        else
        {
            cout<<"1";
            int t[302]={0};
            t['A']=1;
            t['B']=2;
            t['C']=3;
            t['D']=4;
            t['F']=5;
            int a=t[s1[2]],b=t[s2[2]];
            if(a>b)
            {
                int t=a;
                a=b;
                b=t;
            }//baozheng a<b
            if(b<=3||a>=4)
            {
                cout<<"1";
                if(a+1==b)
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
    }
    return 0;
}