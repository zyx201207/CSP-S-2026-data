#include<iostream>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool flag = true;
    if(c1 != c2)
    {
        flag = false;
        cout << 0;
    }
    else cout <<1;
    if(s1[0] == s2[0] && s1[1] == s2[1] && flag) cout << 1;
    else
    {
        flag = false;
        cout << 0;
    }
    if((s1[0] == s2[0] && s1[1] == s2[1]) && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) && s1[2] != s2[2]) cout << 1;
    else
    {
        cout << 0;
        flag = false;
    }
    if(flag && (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2])) cout << 1;
    else cout << 0;
    return 0;
}