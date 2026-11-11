#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)
    {
        cout<<1;
        string h1="",h2="";
        h1+=s2[0];
        h1+=s2[1];
        h2+=s4[0];
        h2+=s4[1];
        if(h1==h2)
        {
            cout<<1;
            char c1=s2[2],c2=s4[2];
            if((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C'))
            {
                cout<<1;
                if(char(c1+1)==c2||char(c2+1)==c1)
                {
                    cout<<1<<endl;
                }
                else cout<<"0"<<endl;
            }
            else
            {

                cout<<"00"<<endl;
            }
        }
        else
        {
            cout<<"000"<<endl;
        }
    }
    else
    {
        cout<<"0000"<<endl;
    }
    return 0;
}
