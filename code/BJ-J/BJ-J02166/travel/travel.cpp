#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    char a=s1[2],b=s2[2];
    if (c1==c2)
    {
        cout<<"1";
        if (s1[0]+s1[1]==s2[0]+s2[1])
        {
            cout<<"1";
            if ((a>='D' && b<'D')||(a<'D' && b>='D'))
            {
                cout<<"00";
            }
            else
            {
                cout<<"1";
                if ((a>='D')||(a==b+1||a==b-1))
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
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







    fclose(stdin);
    fclose(stdout);
}
