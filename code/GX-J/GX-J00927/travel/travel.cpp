#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,n = 0;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
        n += 1000;
    if (s1 == s2)
        n += 100;
    if (n < 1000)
        cout << "0";
    if (n < 100)
        cout << "0";
    if (n < 10)
        cout << "0";
    cout << n;
    return 0;
}
