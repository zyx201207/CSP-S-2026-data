#include <bits/stdc++.h>
using namespace std;
int main()

{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >>c1>>s1>>c2>>s2;
    string st1;
    string st2;
    char sd1 = s1[2];
    char sd2 = s2[2];
    if (c1 == c2)
        cout <<1;
    else
    {
        cout <<"0000";
        return 0;

    }
    if (s1[0] == s2[0] && s1[1] == s2[1])
        cout <<1;
    else
    {
        cout <<"000";
        return 0;

    }
    if(sd1 <= 'C' && sd2 <='C' || sd1 >= 'E' && sd2 >='E')
        cout <<1;
    else
    {
        cout <<"00";
        return 0;
    }
    if(abs(sd1 - sd2) == 1)
        cout <<1;
    else
        cout <<"0";


    return 0;
}
