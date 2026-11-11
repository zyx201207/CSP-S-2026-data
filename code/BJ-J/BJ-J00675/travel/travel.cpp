#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
bool flag1, flag2, flag3;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        cout << 1;
        flag1 = true;
    }
    else cout << 0;

    if(flag1 == true && s1[0] == s2[0] && s1[1] == s2[1])
    {
        cout << 1;
        flag2 = true;
    }
    else cout << 0;

    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') a = 0;
    else a = 1;
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') b = 0;
    else b = 1;
    if(flag2 == true && a == b)
    {
        cout << 1;
        flag3 = true;
    }
    else cout << 0;

    if(flag3 == true && abs(s1[2]-s2[2]) == 1) cout << 1;
    else cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
