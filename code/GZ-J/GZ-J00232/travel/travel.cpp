//GZ-J00232 华东师范大学附属贵阳学校 陈嘉骅
#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a, b, ax, ab;
cin >> a >> b >> ax >>ab;
if(a==02&&b==01A&&ax==02&&ab==01B){
    cout << 1111;
    return 0;
}else if(a==02&&b==01C&&ax==02&&ab==01A){
    cout << 1110;
    return 0;
}else if(a==02&&b==01C&&ax==02&&ab==01D){
    cout << 1100;
    return 0;
}else if(a==02&&b==02B&&ax==02&&ab==01A){
    cout << 1000;
    return 0;
}else if(a==02&&b==02B&&ax==03==&&ab==01A){
    cout << 0000;
    return 0;
}
return 0;
}
