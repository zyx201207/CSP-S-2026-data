#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in")
    freopen("travel.out")
    sting c1,s1,c2,s2;
    cin>>c1 >>s1 >>c2 >> s2;
    if(c1==s1){
        cout << 1;
        if(s1==s2){
            cout << 1;
        }else{
        cout << 0;}
    }else{
    cout << 0;}
    return 0;
}

