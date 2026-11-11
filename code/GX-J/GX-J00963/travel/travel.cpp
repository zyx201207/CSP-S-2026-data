#include <bits/stdc++.h>
using namespace std;
string p1_class,p1_seat,p2_class,p2_seat;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >>p1_class >>p1_seat >>p2_class >>p2_seat;
    if(p1_class!=p2_class){
        cout <<"0000" <<endl;
    }else{
        string p1_pai,p2_pai;
        p1_pai=(p1_seat[0]+p1_seat[1]);
        p2_pai=(p2_seat[0]+p2_seat[1]);
        if(p1_pai!=p2_pai){
            cout <<"1000" <<endl;
        }else{
            char p1_x=p1_seat[2],p2_x=p2_seat[2];
            if(p1_x>='A'&&p1_x<='C'){
                if(p2_x>='D'){
                    cout <<"1100" <<endl;
                }else{
                    if(p1_x=='B'||p2_x=='B'){
                        cout <<"1111" <<endl;
                    }else cout <<"1110" <<endl;
                }
            }else{
                if(p2_x<='C'){
                    cout <<"1100" <<endl;
                }else cout <<"1111" <<endl;
            }
        }
    }
    return 0;
}
