#include <bits/stdc++.h>
using namespace std;

bool flag,flag1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,a2,b2;
    cin >> a >> b >> a2 >> b2;
    for(int i=0;i<a.size();i++){
        if(a[i] != a2[i])flag = 1;
    }
    if(flag == 1){
            cout << "0000";
            return 0;
    }
    else cout << 1;

    for(int i = 0;i< 2;i++){
        if(b[i] != b2[i])flag1 = 1;
    }
    if(flag1 == 1){
            cout << "000";
            return 0;
    }
    else cout << 1;

    if(b[2] == 'F' && b2[2] == 'D' || b[2] == 'D' && b2[2] == 'F' || b[2] <= 'C' && b[2] >= 'A' && b2[2] <= 'C' && b2[2] >= 'A'){
        cout<< 1;
    }
    else {cout << "00";
        return 0;}
    if(abs(b[2] - b2[2]) == 1)cout << 1;
    else cout << 0;



    return 0;
}

