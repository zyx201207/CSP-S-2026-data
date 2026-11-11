#include <bits/stdc++.h>
using namespace std;
string s1, c1, s2, c2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> s1 >> c1 >> s2 >> c2;
    if(s1 != s2){
        printf("0000");
    }
    else{
        printf("1");
        if(c1[0] == c2[0] && c1[1] == c2[1]){
            printf("1");
            if(c1[2] == 'D' || c1[2] == 'F'){
                if(c2[2] == 'D' || c2[2] == 'F'){
                    printf("11");
                }
                else{
                    printf("00");
                }
            }
            else{
                if(c2[2] == 'D' || c2[2] == 'F'){
                    printf("00");
                }
                else{
                    printf("1");
                    if((c1[2] == 'A' && c2[2] == 'B') || (c1[2] == 'B' && c2[2] == 'A') || (c1[2] == 'B' && c2[2] == 'C') || (c1[2] == 'C' && c2[2] == 'B')){
                        printf("1");
                    }
                    else{
                        printf("0");
                    }
                }
            }
        }
        else{
            printf("000");
        }
    }
    return 0;
}
