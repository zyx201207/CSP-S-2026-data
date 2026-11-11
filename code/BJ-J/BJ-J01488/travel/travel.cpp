#include <bits/stdc++.h>
using namespace std;
int main(){
    char b,d=0;
    int a,c=0;
    int k=0;
    cin>>a>>b>>c>>d;
    if (a == c){
        int k[0] =1;
    }
    else{
        int k[0] =0;
    }if (b[0] == d[0] & b[1] == d[1]){
        int k[1] =1;
        if (b[2] =="C" & d[2] == "D"){
             int k[2]=1;
        }else if (d[2] =="C" & b[2] == "D"){
             int k[2]=1;
        }else{
            int k[2]=0;
        }
    }
    else{
        int k[1] = 0;
    }if (b-d == 1){
        int k[3]=1;
    }else{
        int k[3]=0;
    }
    cout<< k ;
    return 0;
}
