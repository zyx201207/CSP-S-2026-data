#include<bits/stdc++.h>
using namespace std;
int chk(char ch) {
    if(ch=='A'||ch=='B'||ch=='C')
        return 1;
    else
        return 0;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    map<char, int> mp;
    string a, b, c, d;
    cin>>a>>b>>c>>d;
    mp.insert({'A', 1});
    mp.insert({'B', 2});
    mp.insert({'C', 3});
    mp.insert({'D', 5});
    mp.insert({'F', 6});
    if(a==c)
        putchar('1');
    else
        putchar('0');
    if(a==c&&b.substr(0, 2)==d.substr(0, 2))
        putchar('1');
    else
        putchar('0');
    if(a==c&&b.substr(0, 2)==d.substr(0, 2)&&chk(b[2])==chk(d[2]))
        putchar('1');
    else
        putchar('0');
    if(a==c&&b.substr(0, 2)==d.substr(0, 2)&&chk(b[2])==chk(d[2])&&abs(mp[b[2]]-mp[d[2]])==1)
        putchar('1');
    else
        putchar('0');
    return 0;
}
//T1难成啥了