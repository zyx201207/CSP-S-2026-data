#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1,s1,c2,s2,ss1,ss2;
    cin >>c1>>s1>>c2>>s2;
    ss1=s1.substr(0,2);
    ss2=s2.substr(0,2);
    if(c1==c2){
        printf("1");
        if(ss1==ss2){
            printf("1");
            if(s1[2]>='D'&&s2[2]>='D')
                printf("11");
            else if(s1[2]<='C'&&s2[2]<='C'){
                    printf("1");
                    if((s2[2]=='B'||s1[2]=='B')||(max(s1[2],s2[2])=='c'&&min(s1[2],s2[2])=='A'))
                        printf("1");
                    else printf("0");
            }
            else printf("00");
        }
        else printf("000");
    }
    else printf("0000");
    return 0;
}
