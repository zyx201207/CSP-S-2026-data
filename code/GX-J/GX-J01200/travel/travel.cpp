#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2,flag1,flag2,flag3;
char aa,ab;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>aa>>c2>>s2>>ab;
    if(c1==c2)
    {
        cout<<"1";
        if(s1==s2)
        {
            cout<<"1";
            if((aa<'D'&&ab<'D')||(aa>'C'&&ab>'C'))
            {
                cout<<"1";
                if((aa>'C'&&ab>'C')||(aa<'C'&&ab<'C')||(aa=='B'&&ab=='C')||(aa=='C'&&ab=='B'))
                    cout<<"1";
                else
                    cout<<"0";
            }
            else
                cout<<"00";
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
    return 0;
}
