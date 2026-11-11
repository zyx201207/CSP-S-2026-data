#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string c1, c2, s1, s2;
int c, s, cc, ss, a[5], pos = -1;
bool weizhi(char wow) {
    return (wow == 'A' || wow == 'B' || wow == 'C');
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2 ;
    c = (c1[0] - '0') * 10 + (c1[1] - '0');
    cc = (c2[0] - '0') * 10 + (c2[1] - '0');
    s = (s1[0] - '0') * 10 + (s1[1] - '0');
    ss = (s2[0] - '0') * 10 + (s2[1] - '0');
    if(c == cc) a[1] = 1;
    if(s == ss) a[2] = 1;
    if(weizhi(s1[2]) == weizhi(s2[2])) a[3] = 1;
    if(s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1) a[4] = 1;
    for(int i = 1; i <= 4; i++) {
        if(a[i]) cout << 1 ;
        else {
            pos = i - 1;
            break;
        }
    }
    if(pos != -1) for(int i = 1; i <= 4 - pos; i++) cout << 0 ;
    return 0;
}
