#include<bits/stdc++.h>
using namespace std;
char n4,m4;
int n1,m1,n2,n3,m2,m3;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> n1 >> n2 >> n4 >> m1 >> m2 >> m4;
    if(n1 == m1){
        cout << 1;
        if(n2 == m2){
            cout << 1;
            n3 = n4 - 'A';
            m3 = m4 - 'A';
            if(n3 <= 2 && m3 <=2){
                cout << 1;
                if(abs(n3 - m3) == 1 ){
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
            else if(n3 >= 3 && m3 >=3){
                cout << "11";
            }
            else{
                cout << "00";
            }

        }
        else{
            cout << "00";
            if(n2-m2==1||n2-m2 == -1){
                cout << 1;
            }
            else{
                cout << 0;
            }
        }
    }
    else{
        cout << "0000";
    }
    return 0;
}
