#include<bits/stdc++.h>
using namespace std;
char s1[10], s2[10], s3[10], s4[10];
bool b1, b2, b3, b4;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%s%s%s%s", &s1, &s2, &s3, &s4);
    if(s1[0] == s3[0] && s1[1] ==s3[1]){
        b1 = true;
    }
    if(s2[0] == s4[0] && s2[1] == s4[1]){
        b2 = true;
        if(s2[2] > s4[2])swap(s2[2], s4[2]);
    }
    if((s2[2] < 'D')==(s4[2] < 'D')){
        b3 = true;
    }
    if(s4[2] - s2[2] == 1 || s2[2] == 'D' && s4[2] == 'F'){
        b4 = true;
    }
    b2 = b1 && b2;
    b3 = b2 && b3;
    b4 = b3 && b4;
    printf("%d%d%d%d", b1, b2, b3, b4);
}
