#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >>c1>>s1>>c2>>s2;
    int pan = 0;
    if (c1==c2)
    {
        cout << 1;
    }
    else
    {
        cout <<0;
    }
    if (c1==c2)
    {
        if (s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout <<1;
        }
        else
        {
            cout <<0;
        }
    }
    else
    {
        cout <<0;
    }
    if (c1==c2)
    {
        if (s1[0]==s2[0]&&s1[1]==s2[1])
        {
            pan = 1;
            if ((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))
            {

                cout <<1;
            }
            else
            {
                cout <<0;
            }
        }
        else
        {
            cout <<0;
        }
    }
    else
    {
        cout <<0;
    }
    if ((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))
    {

        int ans = s1[2]-'0';
        int ans1 = s2[2]-'0';
        if (abs(ans-ans1)==1&&(s1[0]==s2[0]&&s1[1]==s2[1]))
        {
            cout <<1;
        }
        else
        {
            cout <<0;
        }
    }
    else
    {
        cout <<0;
    }
    return 0;
}
