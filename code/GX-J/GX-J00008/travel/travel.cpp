#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,c2,s1,s2;
    cin >>c1 >>c2 >> s1 >> s2;

    string cnt[4];

    if(c1 == c2){
        cnt[0]="1";
        if (s1[0] == s2[0] && s1[1] == s2[1]){
            cnt[1]="1";
            if (s1[2] - 1 == s2[2] || s2[2]-1== s1[2] ){
                cnt[2] = "1";
                cnt[3] = "1";
            }else{
                cnt[2] = "1";
                cnt[3] = "0";
            }
        }else{
            cnt[1] = "0";
            cnt[2] = "0";
            cnt[3] = "0";
        }
    }else
        cnt[0] = "0";
        cnt[1] = "0";
        cnt[2] = "0";
        cnt[3] = "0";
    return 0;
}
