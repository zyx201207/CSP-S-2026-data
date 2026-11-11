#include<bits/stdc++.h>
using namespace std;
int c1,c2,c3,c4,i,A,B,C,D;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> c2 >> c3 >> c4;
    if(i!=01 && i != 16){
        cout << "1";
    }else{
        cout << "0";
    }
    for(int i = 1; i <= 18; i++){
        for(int j = 1; j <=18; j++ ){
            if(i%10==j%10){
                cout << "1";
            }else{
                cout << "0";
            }
            if(i==A||i==B||i==C||i==D)
            if(j==A ||i==B||i==C||i==D){
                cout << "1";
            }else{
                cout << "0";
            }
        }
    }
    return 0;



}
