#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int ca, cb;
    string sa, sb;
    char a[7] = {'A', 'B', 'C', 'O', 'D', 'F'};
    cin >> ca >> sa >> cb >> sb;
    if(ca == cb)cout << "1";
    else cout << "0";
    if(sa[1] == sb[1])cout << "1";
    else cout << "0";
    char pa = sa[2], pb = sb[2], wa, wb;
    for(int i = 0;i < strlen(a);i++){
        if(a[i] == pa){
            wa = i;
        }
        if(a[i] == pb){
            wb = i;
        }
    }
    if(wa < 3 && wb < 3 || wb > 3 && wa > 3){
        cout << "1";
    }else cout << "0";
    if(abs(pb - pa) == 1)cout << "1";
    else cout << "0";
    return 0;
}
