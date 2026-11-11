#include <bits/stdc++.h>
using namespace std;
int main(){
    fstream input;
    fstream output;
    input.open("travel.in",ios_base::in);
    output.open("travel.out",ios_base::out);
    string s[4];
    for(int i = 0;i<4;i++){
        input >> s[i];
    }
    bool res[4];
    res[0] = s[0] == s[2];
    res[1] = res[0] && (s[1][0] == s[3][0] && s[1][1] == s[3][1]);
    res[2] = res[1] && (s[1][0] == s[3][0] && s[1][1] == s[3][1])&&((s[1][2] <= 'C' && s[3][2] <= 'C')||(s[1][2] > 'C' && s[3][2] > 'C'));;
    res[3] = res[2] && (s[1][2] - s[3][2] == 1 || s[1][2] - s[3][2] == -1);
    output << res[0] << res[1] << res[2] << res[3];
    input.close();
    output.close();
    return 0;
}