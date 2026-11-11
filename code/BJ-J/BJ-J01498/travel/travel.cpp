#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travle.in" , "r" , stdin);
    freopen("travle.out" , "w" , stdout);
    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int ans1 = 0 , ans2 = 0 , ans3 = 0 , ans4 = 0;
    if(c1 == c2){
        ans1 = 1;
        string a , b;
        a = s1[0] + s1[1];
        b = s2[0] + s2[1];
        if(a == b){
            ans2 = 1;
            int C = s1[2] - 'A' , D = s2[2] - 'A';
            if((C <= 2 && D <= 2) || (C > 2 && D > 2)){
                ans3 = 1;
            }
            if((C == 0 && D == 1) || (C == 1 && D == 0) || (C == 2 && D == 1) || (C == 1 && D == 2) || (C == 3 && D == 5) || (C == 5 && D == 3)){
                ans4 = 1;
            }
        }
    }
    cout << ans1 << ans2 << ans3 << ans4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}