#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,f=0;
    cin>>a>>b;
    cin>>c>>d>>e>>f;
    int k,m;
    if (a ==1){
        int k=c;
    }else if (a ==2){
        int k=d;
    }else if (a ==3){
        int k=e;
    }else if (a ==4){
        int k=f;
    }if (b ==1){
        int m=c;
    }else if (b ==2){
        int m=d;
    }else if (b ==3){
        int m=e;
    }else if (b ==4){
        int m=f;
    }cout<<k & m;
    return 0;
}
