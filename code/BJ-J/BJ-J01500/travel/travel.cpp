#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool op1, op2, op3 ,op4;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1[0] == c2[0] && c1[1] == c2[1])
        op1 = 1;
    if( op1 && s1[0] == s2[0] && s1[1] == s2[1])
        op2 = 1;
    if(op2 && ((s1[2] <= 'C'&& s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')))
       op3 = 1;
    if(op3 && (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]))
        op4 = 1;
    cout << op1 << op2 << op3 << op4;
    return 0;
}
