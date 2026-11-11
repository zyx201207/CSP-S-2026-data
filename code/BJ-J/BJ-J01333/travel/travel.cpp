#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);cin.tie(0);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >>c2 >>s2;
    if(c1 == c2){
        cout << "1";
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            cout << "1";
            int a = s1[2] - 'A' + 1;
            int b = s2[2] - 'A' + 1;
            if((a <= 3 && b <= 3)||(a >= 4 && b >= 4)){
                cout << "1";
                if((a + 1 == b || a - 1 == b)|| (a >= 4)){
                    cout << "1";
                }
                else{
                    cout <<"0";
                }
            }
            else{
                cout << "0";
            }
        }
        else{
            cout <<"000";
        }
    }
    else{
        cout <<"0000";
    }
}