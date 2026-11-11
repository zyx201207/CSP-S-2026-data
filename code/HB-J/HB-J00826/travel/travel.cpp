#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int a1 = 0,a2 = 0,a3 = 0,a4 = 0;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) a1 = 1;
    if (a1 && (s1[0] == s2[0]) && (s1[1] == s2[1])) a2 = 1;
    char s1__ = s1[2],s2__ = s2[2];
    if (a2 && (((s1__ == 'A' || s1__ == 'B' || s1__ == 'C') && (s2__ == 'A' || s2__ == 'B' || s2__ == 'C')) || ((s1__ == 'D' || s1__ == 'F') && (s2__ == 'D' || s2__ == 'F')))) a3 = 1;
    if (a3 && ((s1__ == 'A' && s2__ == 'B') || (s1__ == 'B' && (s2__ == 'A' || s2__ == 'C')) || (s1__ == 'C' && s2__ == 'B') || (s1__ == 'D' && s2__ == 'F') || (s1__ == 'F' && s2__ == 'D'))) a4 = 1;
    cout << a1 << a2 << a3 << a4;
    return 0;
}
