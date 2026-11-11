#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) printf("1");
    else{ printf("0000");return 0; }
    string p1,p2;
    for(LL i = 0;i <= 1;i++) p1 += s1[i];
    for(LL i = 0;i <= 1;i++) p2 += s2[i];
    if(p1 == p2) printf("1");
    else{ printf("000");return 0; }
    char w1 = s1[2],w2 = s2[2];
    if(w1 == 'A'){
        if(w2 == 'B') printf("11");
        else if(w2 == 'C') printf("10");
        else printf("00");
    }else if(w1 == 'B'){
        if(w2 == 'A' || w2 == 'C') printf("11");
        else printf("00");
    }else if(w1 == 'C'){
        if(w2 == 'A') printf("10");
        else if(w2 == 'B') printf("11");
        else printf("00");
    }else if(w1 == 'D'){
        if(w2 == 'E') printf("11");
        else printf("00");
    }else{
        if(w2 == 'D') printf("11");
        else printf("00");
    }
    return 0;
}
