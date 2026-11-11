#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a,b,c,d;
int main()
{
    freopen("travle.in","r",stdin);
    freopen("travle.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    for(int i=0;i<2;i++)
    {
        a+=s1[i]-'0';
        b+=s3[i]-'0';
    }
    if(a==b)
    {
        cout<<'1';
        for(int i=0;i<2;i++)
        {
            c+=s2[i]-'0';
            d+=s4[i]-'0';
        }
        if(c==d)
        {
            cout<<'1';
            if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>'C'&&s4[2]>'C'))
            {
                cout<<'1';
                if(s2[2]-s4[2]==1||s4[2]-s2[2]==1)
                {
                    cout<<'1';
                }
                else cout<<'0';
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;

}
