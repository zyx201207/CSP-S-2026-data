#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1, s1, c2, s2;
bool flag1, flag2, flag3, flag4;
bool check(int x, int y){
    if(x == 4 && y == 3){
        return false;
    }
    if(y == 4 && x == 3){
        return false;
    }
    return true;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    flag1 = flag2 = flag3 = flag4 = 1;
    for(int i = 0; i < c1.size(); i++){
        if(c1[i] != c2[i]){
            flag1 = 0;
        }
    }
    for(int i = 0; i < 2; i++){
        if(s1[i] != s2[i]){
            flag2 = 0;
        }
    }
    if(flag1 == 0){
        flag2 = 0;
    }
    int num1, num2;
    num1 = s1[2] - 'A' + 1;
    num2 = s2[2] - 'A' + 1;
    //cout << num1 << " " << num2 << endl;
    flag3 = 0;
    if(check(num1, num2) && flag1 && flag2){
        flag3 = 1;
    }
    flag4 = 0;
    if(abs(num1 - num2) == 1 && flag1 && flag2 && flag3){
        flag4 = 1;
    }
    cout << flag1 << flag2 << flag3 << flag4 << endl;
    return 0;
}
