#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    char c1[2];
    char s1[3];
    char c2[2];
    char s2[3];
    int r[2];
    int x[2];
    //cin
    for (int i=0;i < 2;i++){
        cin >> c1[i];
    }
    for (int i=0;i < 3;i++){
        cin >> s1[i];
//        if (i < 2){
//            cin >> r[i];
//        }
    }
    for (int i=0;i < 2;i++){
        cin >> c2[i];
    }
    for (int i=0;i < 3;i++){
        cin >> s2[i];
//        if (i < 2){
//            cin >> x[i];
//        }
    }

    int q1,q2,q3,q4;
    //q1
    for(int i=0;i<2;i++){
        if (c1[i] != c2[i]){
            q1 = 0;
            break;
        }else{
            q1 = 1;
        }
    }
    //q2
    for(int i=0;i<2;i++){
        if (s1[i] != s2[i]){
            q2 = 0;
            break;
        }else{
            q2 = 1;
        }
    }
    //q3
    string n1,n2;
    n1 = s1[2];
    n2 = s2[2];
    if (q2 == 1){

        cout << n1 << n2;
        q3 = 1;
    }else{
        q3 = 0;
    }
    //q4
    if (q3 == 1){
        int x,y;
        x = r[0] * 10 + r[1];
        y = r[0] * 10 + r[1];
        if (x + 1 == y || x - 1 == y){
            q4 = 1;
        }else{
            q4 = 0;
        }
    }else{
        q4 = 0;
    }

    cout << q1 << q2 << q3 << q4 << endl;

    const char* n5 = "A";

    if (n5 == "A"){
        cout << "1";
    }





    return 0;
}
