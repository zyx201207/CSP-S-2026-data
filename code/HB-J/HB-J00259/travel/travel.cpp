#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1, s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a, b;
    cin >> a >> s1 >> b >> s2;
    if(a == b) putchar('1');
    else{
        printf("0000");
        return 0;
    }
    int row1 = s1[0] * 10 + s1[1];
    int row2 = s2[0] * 10 + s2[1];
    char c1 = s1[2], c2 = s2[2];
    if(row1 == row2){
        putchar('1');
        if(c1 == 'A' || c1 == 'B' || c1 == 'C'){
            if(c2 == 'A' || c2 == 'B' || c2 == 'C'){
                putchar('1');
                if(c2 == c1 + 1 || c2 == c1 - 1) putchar('1');
                else putchar('0');
            }else printf("00");
        }else{
            if(c2 == 'D' || c2 == 'F'){
                putchar('1');
                if(c2 == c1 + 1 || c2 == c1 - 1) putchar('1');
                else putchar('0');
            }else printf("00");
        }
    }else printf("000");
    return 0;
}
