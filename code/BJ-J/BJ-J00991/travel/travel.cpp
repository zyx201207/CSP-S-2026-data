#include <bits/stdc++.h>
using namespace std;
int c[8]{0,0,0,1,-1,1};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x,y;
    char a,a_,a__,b,b_,b__;
    cin >> x >> a >> a_ >> a__ >> y >> b >> b_ >> b__;
    if(x == y){
        if(a == b && a_ == b_){
            if(c[a__-'A'] == c[b__-'A']){
                if((a__=='C' && b__=='A')||(a__=='A' && b__ =='C')){
                    cout << "1110";
                }else{
                    cout << "1111";
                }
            }else{
                cout << "1100";
            }
        }else{
            cout << "1000";
        }
    }else{
        cout << "0000";
    }
    return 0;
}
