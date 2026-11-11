#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    int c1 , c2;
    string s1 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout<< 1;
    else cout << 0;
    int a = (s1[0] - '0') * 10 + (s1[1] - '0'), b = (s2[0] - '0') * 10 + (s2[1] - '0');
    char x = s1[2] , y = s2[2];
    if (a == b) cout<< 1;
    else cout << 0;
    if (a == b && (x < 'C' && y < 'C' || 'C' <  x && 'C' < y)) cout<< 1;
    else cout << 0;
    if (a == b && (x < 'C' && y < 'C' || 'C' <  x && 'C' < y) && ((x == 'A' && y == 'B') || (x == 'B' && y == 'C') || (x == 'D' && y == 'F'))) cout<< 1;
    else cout << 0;
    cout << endl;
    return 0;
}