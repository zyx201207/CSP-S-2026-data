#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char zv[5]={'A','B','C','D','F'};
    string a,b,a2,b2;
    cin >> a >> b >> a2 >> b2;
    if(a==a2){
        if(b[0]==b2[0] && b[1]==b2[1]){
            if(b[2]-'A'<=2 && b2[2]-'A'<=2){
                cout <<1 << 1 << 1;
            }else {
                cout << 1 <<1 <<0;
            }
            int dy2,dy3;
            for(int i=0;i<5;i++){
                if(b[2]==zv[i]){
                    dy2=i+1;
                }
                if(b2[2]==zv[i]){
                    dy3=i+1;
                }
            }
            if(abs(dy2-dy3)==1){
                cout << 1;
            }else {
                cout <<0;
            }
        }else {
            cout << 1 <<0 <<0 <<0;
        }
    }else {
    cout <<0<<0<<0<<0;
    }
    return 0;
}
