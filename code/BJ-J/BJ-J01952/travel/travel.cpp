#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << "1";
    else cout << "0";
    string tmp1 = "";
    string tmp2 = "";
    for(int i = 0;i <= 1;i++)
    {
        tmp1 += s1[i];
        tmp2 += s2[i];
    }
    if((c1==c2)&&(tmp1==tmp2)) cout << "1";
    else cout << "0";
    bool b = ((c1==c2)&&(tmp1==tmp2));
    char n1 = s1[2];
    char n2 = s2[2];
    if(b)
    {
        if(((n1<='C')&&(n2<='C'))||((n1>='D')&&(n2>='D'))) cout << "1";
        else cout << "0";
    }
    else cout << "0";
    if((tmp1 == tmp2)&&(c1 == c2))
    {
        if(n1 == 'A')
        {
            if(n2 == 'B') cout << "1";
            else cout << "0";
        }
        else if(n1 == 'B')
        {
            if((n2 == 'A')||(n2 == 'C')) cout << "1";
            else cout << "0";
        }
        else if(n1 == 'C')
        {
            if(n2 == 'B') cout << "1";
            else cout << "0";
        }
        else if(n1 == 'D')
        {
            if(n2 == 'F') cout << "1";
            else cout << "0";
        }
        else if(n1 == 'F')
        {
            if(n2 == 'D') cout << "1";
            else cout << "0";
        }
        else cout << "0";
    }
    else
    {
        cout << "0";
    }
    return 0;
}
