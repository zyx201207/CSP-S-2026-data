#include<bits/stdc++.h>
using namespace std;
int b[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a[4];
    int b[4];
    for(int i=0;i<4;i++){
        cin>>a[i];
        b[i]=0;
    }
    if(a[0]==a[2]){
        b[0]=1;
    }
    if(a[1][0]==a[3][0] and a[1][1]==a[3][1]){
        if(b[0]==1){
            b[1]=1;
        }
    }
    if(a[1][2]<='C' and a[3][2]<='C'){
        if(b[1]==1){
            b[2]=1;
        }
    }
    if(a[1][2]>'C' and a[3][2]>'C'){
        if(b[1]==1){
            b[2]=1;
        }
    }
    if(a[1][2]+1==a[3][2] or a[1][2]-1==a[3][2]){
        if(b[2]==1){
            b[3]=1;
        }
    }
    for(int i=0;i<4;i++){
        cout<<b[i];
    }
}
