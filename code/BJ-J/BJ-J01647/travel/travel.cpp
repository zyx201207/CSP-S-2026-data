#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    char ans[5] = {};
    if(c1 == c2) ans[0] = '1';
    else ans[0] = '0';
    if((int(s1[0]) == int(s2[0]) && int(s1[1]) == int(s2[1])) && ans[0] == '1') ans[1] = '1';
    else ans[1] = '0';
    if(ans[1] == '1'){
        if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
            if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') ans[2] = '1';
            else ans[2] = '0';
        }
        else{
            if(s2[2] == 'D' || s2[2] == 'F') ans[2] == '1';
            else ans[2] = '0';
        }
    }else{
        ans[2] = '0';
    }
    if(ans[2] == '1'){
        if(s1[2] == 'D' || s1[2] == 'F' || s1[2] == 'B' || s2[2] == 'B') ans[3] = '1';
        else ans[3] = '0';
    }else{
        ans[3] = '0';
    }
    string answer;
    for(int i = 0;i < 4;i++){
        cout << ans[i];
    }
    return 0;
}

