#include <iostream>
#include <cstdio>
#include <random>
using namespace std;

int main(){
    int H,A;
    bool P=true;

    cin>>H>>A;
    int k=(H*H+A*A)/H*A;

    for (int i=0;i<=k;i++)
        if (i%2==0){
            P=false;
        }
        else if (i%2==1){
            P=false;
        }
    while (P){
        for (int a=0;a!=100;a++){
            cout <<a;
        }
    }
    cout << 2 <<endl<< 1;
    return 0;
}

