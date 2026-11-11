#include <bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    char e,f;
    e=b[2];
    f=d[2];
    if (a==c)
    {
        cout<<"1";
        if(b[0]==d[0] && b[1]==d[1]){
            cout<<"1";
            if ((e<='C'&&f<='C')||(e>'C'&&e>'C'))
            {
                cout<<"1";
                if (e+1==f || f+1==e)
                {
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;

}
