#include<bits/stdc++.h>
using namespace std;
string R1,R2,X1,X2;
int r1,r2,r3,x1,x2,x3;
int a[3];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>R1>>R2>>X1>>X2;
    r1=R1[0]*10+R1[1];
    x1=X1[0]*10+X1[1];
    r2=R2[0]*10+R2[1];
    x2=X2[0]*10+X2[1];
    r3=R2[2]-'A';
    x3=X2[2]-'A';
    if(r1==x1)a[0]=1;
    if(r1==x1&&r2==x2){
        a[1]=1;
    }
    if(r1==x1&&r2==x2&&(((r3>=0&&r3<=2)&&(x3>=0&&x3<=2))||((r3>=3&&r3<=4)&&(x3>=3&&x3<=4)))){
        a[2]=1;
    }
    if(r1==x1&&r2==x2&&(((r3>=0&&r3<=2)&&(x3>=0&&x3<=2))||((r3>=3&&r3<=4)&&(x3>=3&&x3<=4)))&&abs(r3-x3)==1){
        a[3]=1;
    }
    cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0;
}
