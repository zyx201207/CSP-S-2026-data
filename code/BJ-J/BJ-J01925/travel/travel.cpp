#include <iostream>
#include <cstdio>
using namespace std;

int c1, c2, jj1, jj2;
string s1, s2;
char t1, t2;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    jj1=(s1[0]-'0')*10+(s1[1]-'0');
    jj2=(s2[0]-'0')*10+(s2[1]-'0');
    t1=s1[2];
    t2=s2[2];
    cout << (c1==c2);
    cout << (c1==c2 && jj1==jj2);
    cout << (c1==c2 && jj1==jj2 && (((t1>='A' && t1<='C') && (t2>='A' && t2<='C')) || ((t1>='D' && t1<='F') && (t2>='D' && t2<='F'))));
    cout << (c1==c2 && jj1==jj2 && (((t1>='A' && t1<='C') && (t2>='A' && t2<='C')) || ((t1>='D' && t1<='F') && (t2>='D' && t2<='F'))) && abs(t1-t2)==1) << endl;
    return 0;
}