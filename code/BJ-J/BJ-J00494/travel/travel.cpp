#include <bits/stdc++.h>
using namespace std;
int bought[6];
string c1,s1,c2,s2;
int main ()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1!=c2)
    {
        cout << "0000";
    }
    else
    {
        cout << 1;
        if ((s1[0]!=s2[0])||(s1[1]!=s2[1]))
        {
            cout << "000";
        }
        else
        {
            cout << 1;
            bought[s1[2]-'A']=1;
            bought[s2[2]-'A']=1;
            if ((bought[0]+bought[1]+bought[2]!=2)&&(bought[4]+bought[5]!=2))
            {
                cout << "00";
            }
            else
            {
                cout << 1;
                bool flag=false;
                for (int i=0;i<=4;i++)
                {
                    if (bought[i]&&bought[i+1])
                    {
                        flag=true;
                    }
                }
                if (flag)
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
        }
    }
    return 0;
}
