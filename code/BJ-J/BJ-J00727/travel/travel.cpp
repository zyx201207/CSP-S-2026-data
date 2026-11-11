#include<bits/c++.h>
using namespace std;
int a,c,b[2],d[2];
int main(){
    cin << a;
    cin << b;
    cin << c;
    cin << d;
    if (a != 01 and a != 16 and a == c and b[0]  == d[0] and b[1] == d[1] and b[2] == A and d[2] == B or b[2] == B and d[2] == C or b[2] == D and d[2] == F){
        cout >> '1111';
        }
    if (a != 01 and a != 16 and a == c and b[0]  == d[0] and b[1] == d[1] and b[2] == A and d[2] == C){
        cout >> '1110';
        }
    if (a != 01 and a != 16 and a == c and b[0]  == d[0] and b[1] == d[1] and b[2] == A and d[2] == D or b[2] == A and d[2] == F or b[2] == B and d[2] == D or b[2] == B and d[2] == F or b[2] == C and d[2] == D or b[2] == C and d[2] == F){
        cout >> '1100';
        }
    if (a != 01 and a != 16 and a == c and b[0] != d[0] or b[1] != d[1]){
        cout >> '1000';
        }
    if (a != c and a != 01 and a != 16){
        cout >> '0000';
        }
return 0;
}