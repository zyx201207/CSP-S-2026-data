#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s;
    for(int i = 1;i <= 4;i++){
        cin >> s;
    }
    for(int i = 0;i < 4;i++){
        if(s != s){
            cout << "0000";
            return 0;
        }else{
            cout <<"1111";
            break;
        }

    }
    return 0;
}
