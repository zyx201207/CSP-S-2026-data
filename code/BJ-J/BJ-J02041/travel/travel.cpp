#include<bits/stdc++.h>
using namespace std;

string c1 , s1 , c2 , s2;

bool isnear(char a , char b)
{
    if((a == 'F' && b == 'D') || (a == 'D' && b == 'F'))
        return 1;
    else
        return 0;
}

int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    bool flag = (c1 == c2);
    cout << (c1 == c2);
    cout << (flag && s1[0] == s2[0] && s1[1] == s2[1]);
    cout << (flag && s1[0] == s2[0] && s1[1] == s2[1] && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')));
    cout << (flag && s1[0] == s2[0] && s1[1] == s2[1] && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) && (abs(s1[2] - s2[2]) == 1 || isnear(s1[2] , s2[2])));

    fclose(stdin);
    fclose(stdout);

    return 0;
}
