#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
bool f1(char a, char b){
    if(a == 'A' || a == 'B' || a == 'C'){
        if(b == 'A' || b == 'B' || b == 'C'){
            return true;
        }
        else return false;
    }
    else {
        if(b == 'A' || b == 'B' || b == 'C'){
            return false;
        }
        else return true;
    }
}
bool f2(char a, char b){
    if((a == 'A' && b == 'C') || (a == 'C' && b == 'A')) return false;
    else return true;
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int a1 = int(s1[0] - 48) * 10 + int(s1[1] - 48);
    int a2 = int(s2[0] - 48) * 10 + int(s2[1] - 48);
    if(c1 == c2){
        printf("1");
        if(a1 == a2){
            printf("1");
            if(f1(s1[2], s2[2])){
                printf("1");
                if(f2(s1[2], s2[2])){
                    printf("1");
                }
                else printf("0");
            }
            else printf("00");
        }
        else printf("000");
    }
    else printf("0000");
    return 0;
}
//Trick||Treat!
