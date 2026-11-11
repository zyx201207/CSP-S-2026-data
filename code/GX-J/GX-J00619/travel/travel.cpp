#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int c1, c2, pai1, pai2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=1;i++)
    {
        pai1=pai1*10+(int)s1[i];
        pai2=pai2*10+(int)s2[i];
    }
    if(c1==c2)//1
    {
        cout<<"1";
        if(pai1==pai2)//2
        {
            cout<<"1";
            if(((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')))//3
            {
                cout<<"1";
                if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')//4
                {
                    cout<<"1";return 0;
                }
                else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C'))
                {
                    cout<<"1";return 0;
                }
                else
                {
                    cout<<"0";return 0;
                }
            }
            else
            {
                cout<<"00";
                return 0;
            }
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    else//1
    {
        cout<<"0000";
        return 0;
    }
    return 0;
}
