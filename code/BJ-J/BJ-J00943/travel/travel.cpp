#include <bits/stdc++.h>
using namespace std;


string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> c1 >>s1 >> c2 >> s2;

    if(c1==c2)
    {

        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            bool a = ((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'));
            bool b = ((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'));
            if(a)
            {

                if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
                    {
                        cout << "1111";
                        return 0;
                    }
                else
                {
                    cout << "1110";
                    return 0;
                }


            }
            else if(b)
            {
                cout << "1111";
                return 0;
            }
            else{
                cout << "1100";
            }
        }
        else
        {

            cout << "1000";
            return 0;
        }
    }
    else
    {
        cout << "0000";
        return 0;
    }





}
