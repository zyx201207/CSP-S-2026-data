#include <bits/stdc++.h>
using namespace std;
char s1[10], s2[10];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int c1, c2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1==c2){
        cout << "1";
    }else{
        cout << "0000";
        return 0;
    }

    bool t = 1;
    for (int i = 0;i<2;i++){
        if (s1[i]!=s2[i]){
            t = 0;
        }
    }
    if (t){
        cout << "1";
    }else{
        cout << "000";
        return 0;
    }
    int n1 = s1[2]-'A';
    int n2 = s2[2]-'A';

    if (n1>=3&&n2>=3){
        cout << "11";
        return 0;
    }else if (n1<3&&n2<3){
        cout << "1";
        if (n1-n2==1||n2-n1==1){
            cout << "1";
            return 0;
        }else{
            cout << "0";
            return 0;
        }
    }else {
        cout << "00";
    }

    return 0;
}
