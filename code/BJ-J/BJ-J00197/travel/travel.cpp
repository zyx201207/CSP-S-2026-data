#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,s1,a2,s2;
    cin>>a1>>s1>>a2>>s2;

    if(a1==a2)
    {

        cout<<1;
        string p1,p2;
        char n1,n2;

        n1=s1[2];

        n2=s2[2];

        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {

            cout<<1;
            if(n1<='C'&&n2<='C'||n1>'C'&&n2>'C')
            {

                cout<<1;
                if(abs(n1-n2)==1&&n1<='C'&&n2<='C'||n1=='D'&&n2=='F'||n2=='D'&&n1=='F')
                {

          cout<<1;
                }
                else
                {

                    cout<<0;
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
    }
    else
    {

        cout<<"0000";
    }

    return 0;
    fclose(stdin);
    fclose(stdout);
}