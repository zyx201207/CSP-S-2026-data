#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2, flag = "0000";
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        flag[0] = '1';
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            flag[1] = '1';
            if('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C'){
                flag[2] = '1';
                int n = abs(s1[2] - s2[2]);
                if(n == 1){
                    flag[3] = '1';
                }
            }else if('D' <= s1[2] && s1[2] <= 'E' && 'D' <= s2[2] && s2[2] <= 'E'){
                flag[2] = '1';
                int n = abs(s1[2] - s2[2]);
                if(n == 1){
                    flag[3] = '1';
                }
            }
        }
    }
    cout << flag;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
