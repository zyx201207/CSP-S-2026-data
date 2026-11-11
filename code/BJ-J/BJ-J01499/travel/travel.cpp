#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int c1,c2;
string s1,s2,a1,a2;
char t1,t2;
bool flag1,flag2,flag3,flag4;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> c1 >> s1 >> c2 >> s2;

    a1 = s1[0] + s1[1];
    a2 = s2[0] + s2[1];
    t1 = s1[2];
    t2 = s2[2];

    if(c1 == c2){
        flag1 = true;
    }
    if(flag1 == true && a1 == a2){
        flag2 = true;
    }
    if(flag2 == true && ((t1 <= 'C' && t2 <= 'C') || (t1 > 'C' && t2 > 'C'))){
       flag3 = true;
    }
    if(flag3 == true && abs(t1 - t2) == 1){
        flag4 = true;
    }

    if(flag1 == true){
        cout << 1;
    }
    else{
        cout << 0;
    }
    if(flag2 == true){
        cout << 1;
    }
    else{
        cout << 0;
    }
    if(flag3 == true){
        cout << 1;
    }
    else{
        cout << 0;
    }
    if(flag4 == true){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
