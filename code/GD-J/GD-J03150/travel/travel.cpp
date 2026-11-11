#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a1,a2;
char b1,b2;
int main() {
    cin >> c1 >> s1 >> c2 >> s2;
    a1=(s1[0]-'0')*10+(s1[1]-'0'),a2=(s2[0]-'0')*10+(s2[1]-'0');
    b1=s1[2],b2=s2[2];
    cout <<(c1==c2);
    cout <<(c1==c2&&a1==a2);
    cout <<(c1==c2&&a1==a2&&((b1<='C'&&b2<='C')||(b1>='D'&&b2>='D')));
    cout <<(c1==c2&&a1==a2&&((b1+1==b2||b2+1==b1)&&!(b1=='C'&&b2=='D')&&!(b1=='D'&&(b2=='C'))));
    return 0;
}
