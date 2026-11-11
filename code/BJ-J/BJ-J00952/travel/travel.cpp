#include<bits/stdc++.h>
using namespace std;
bool f1,f2,f3,f4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int a,b,c,d;
    a=s1[1]-'0'+(s1[0]-'0')*10;
    b=s2[1]-'0'+(s2[0]-'0')*10;
    c=s3[1]-'0'+(s3[0]-'0')*10;
    d=s4[1]-'0'+(s4[0]-'0')*10;
    char c1=s2[2];
    char c2=s4[2];


    if(a==c)
    {
        if(b==d)
        {
            if(((c1=='F'&&c2=='D')||(c1=='D'&&c2=='F'))||((c1=='A'&&c2=='B')||(c1=='B'&&c2=='C')||(c1=='A'&&c2=='C')||(c1=='B'&&c2=='A')||(c1=='C'&&c2=='B')||(c1=='C'&&c2=='A')))
            {
                if((c1=='F'&&c2=='D')||(c1=='D'&&c2=='F'))
                {
                    cout<<1<<1<<1<<1;
                    return 0;
                }
                else if((c1=='A'&&c2=='B')||(c1=='B'&&c2=='C')||(c1=='B'&&c2=='A')||(c1=='C'&&c2=='B'))
                {
                    cout<<1<<1<<1<<1;
                    return 0;
                }
                else
                {
                    cout<<1<<1<<1<<0;
                    return 0;
                }
            }
            else
            {
                cout<<1<<1<<0<<0;
                return 0;
            }
        }
        else
        {
            cout<<1<<0<<0<<0;
            return 0;
        }
    }
    else
    {
        cout<<0<<0<<0<<0;
    }
}
