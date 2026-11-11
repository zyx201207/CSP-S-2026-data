#include <bits/stdc++.h>
using namespace std;
string ans = "";
string c1,c2,s1,s2;
bool flag1=1,flag2=1;
void row(string a, string b){
    if (a[0] == b[0] && a[1] == b[1]){
            ans += '1';
            flag1 = 1;
    }
    else{
        ans += '0';
        flag1 = 0;
    }
    return;
}
void guodao(char a, char b){
    if (a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C' && flag1){
            ans += '1';
            flag2 = 1;
    }
    else if( (a == 'D' || a == 'F' ) && (b == 'D' || b == 'F' ) && flag1){
            ans += '1';
            flag2 = 1;
    }
    else{
        ans += '0';
        flag2 = 0;
    }
    return;

}

void near(char a, char b){
    if (a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C' && abs(b-a) == 1 && flag2){
            ans += '1';
    }
    else if( (a == 'D' || a == 'F' ) && (b == 'D' || b == 'F' ) && (abs(b-a) == 2) && flag2){
            ans += '1';
    }
    else ans += '0';
    return;

}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c1 >> s1;
    cin >> c2 >> s2;
    if (c1 != c2){
        cout << "0000";
        return 0;
    }
    ans += '1';
    row(s1,s2);
    guodao(s1[2],s2[2]);
    near(s1[2],s2[2]);
    cout << ans;
    return 0;
}
