#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[5],s1[5],c2[5],s2[5],ans1 = '0',ans2 = '0',ans3 = '0',ans4 = '0';
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1[0] == c2[0] && c1[1] == c2[1]){
        ans1 = '1';
    }
    else ans1 = '0';
    if (c1[0] == c2[0] && c1[1] == c2[1] && s2[0] == s1[0] && s1[1] == s2[1]){
        ans2 = '1';
    }
    else ans2 = '0';
    if (c1[0] == c2[0] && c1[1] == c2[1] && s2[0] == s1[0] && s1[1] == s2[1]){
        if ((s2[2] <= 'C' && s2[2] >= 'A' && s1[2] <= 'C' && s1[2] >= 'A') || (s2[2] <= 'E' && s2[2] >= 'D' && s1[2] <= 'E' && s1[2] >= 'D')){
            ans3 = '1';
        }
    }
    else ans3 = '0';
    if (c1[0] == c2[0] && c1[1] == c2[1] && s2[0] == s1[0] && s1[1] == s2[1]){
        if ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'D' && s2[2] == 'E') || (s2[2] == 'A' && s1[2] == 'B') || (s2[2] == 'B' && s1[2] == 'C') || (s2[2] == 'D' && s1[2] == 'E')){
            ans4 = '1';
        }
    }
    else ans4 = '0';
    cout << ans1 << ans2 << ans3 << ans4;
    return 0;
}
