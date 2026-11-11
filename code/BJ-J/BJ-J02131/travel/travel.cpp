#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << "0000";
        return 0;
    }
    cout << 1;
    for(int i = 0;i<2;i++){
        if(s1[i]!=s2[i]){
            cout << "000";
            return 0;
        }
    }
    cout << 1;
    if((s1[2]<='C' && s2[2]>='D') || (s1[2]>='D' && s2[2]<='C')){
        cout << "00";
        return 0;
    }
    cout << 1;
    if(abs(s1[2]-s2[2])<=1){
        cout << 1;
        return 0;
    }
    cout << 0;
    return 0;
}
