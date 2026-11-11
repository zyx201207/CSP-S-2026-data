#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    string a1, a2, b1, b2, ans="";
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1==b1){
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            if (a2[2] == 'F' && b2[2] == 'D' || ((a2[2] >= 'A' && a2[2] <= 'C') && (b2[2] >= 'A' && b2[2] <= 'C'))){
                if (abs(int(a2[2]) - int(b2[2])) != 1||(a2[2]=='D'&&b2[2]=='C'||a2[2]=='C'&&b2[2]=='D')){
                    ans = "1110";
                }else{
                    ans = "1111";
                }
            }else{
                ans = "1100";
            }
        }else{
            ans = "1000";
        }
    }else{
        ans = "0000";
    }
    cout << ans;
    return 0;
}
