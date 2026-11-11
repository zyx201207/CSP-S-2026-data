#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<0000;
        if(a2==b2){
            cout<<1111;
        }
    }
    else{
        cout<<1000;
    }




    return 0;
}
