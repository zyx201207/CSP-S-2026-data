#include<bits/stdc++.h>
using namespace std;
string ans = "";
int cx, cy;
string sx, sy;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> cx >> sx >> cy >> sy;
    if(cx == cy && cx > 01 && cx != 16 && cy > 01 && cy != 16){
        ans += '1';
    }
    else{
        cout << "0000";
        return 0;
    }

    int nx = (sx[0] - '0') * 10 + sx[1] - '0';
    int ny = (sy[0] - '0') * 10 + sy[1] - '0';
    char wx = sx[2], wy = sy[2];
    if(nx == ny){
        ans += '1';
    }
    else{
        cout << "1000";
        return 0;
    }

    if((wx >= 'A' && wx <= 'C' && wy >= 'A' && wy <= 'C') || ((wx == 'D' || wx == 'F') && (wy == 'D' || wy == 'F'))){
        ans += '1';
    }
    else{
        cout << "1100";
        return 0;
    }

    if(wx >= 'A' && wx <= 'C' && wy >= 'A' && wy <= 'C'){
        if(wx + 1 == wy || wy + 1 == wx){
            cout << "1111";
            return 0;
        }
        else{
            cout << "1110";
            return 0;
        }
    }

    if((wx == 'D' || wx == 'F') && (wy == 'D' || wy == 'F')){
        cout << "1111";
        return 0;
    }
    else{
        cout << "1110";
        return 0;
    }
    for(int i = 1; i <= 4 - ans.size(); i ++){
        ans += '0';
    }
    cout << ans;
    return 0;
}
