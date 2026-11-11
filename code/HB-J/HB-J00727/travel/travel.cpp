#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string R1,R2,X1,X2;
    cin>>R1>>R2>>X1>>X2;
    if(R1==X1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    int a=0;
    for(int i=0;i<2;i++){
        if(R2[i]==X2[i]){
                a++;
        }
    }
    if(a==2 && (R1==X1)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    int u=0;
    for(int i=0;i<3;i++){
        if(i==2 && (R2[i]>'C' && X2[i]>'C') || (R2[i]<'D' && X2[i]<'D')){
            u++;
        }
    }
    if(u==1 && a==2 && R1==X1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if((X2[2]-1==R2[2] || X2[2]+1==R2[2]) && u==1 && a==2 && (R1==X1)){
        cout<<1;
    }
    else{
        cout<<0;
    }


    return 0;
}
