#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    int ap,bp,as,bs;
    int k1=0,k2=0,k3=0,k4=0;//车厢，排，侧，邻
    cin>>a1>>a2>>b1>>b2;
    ap=(a2[0]-'0')*10+(a2[1]-'0');
    bp=(b2[0]-'0')*10+(b2[1]-'0');
    as=a2[2]-'A';
    bs=b2[2]-'A';
    if(a1==b1){
        k1=1;
        if(ap==bp){
            k2=1;
            if(as>2&&bs>2){
                k3=k4=1;
            }else if(as<3&&bs<3){
                k3=1;
                if(as-bs==1||bs-as==1){
                    k4=1;
                }
            }
        }
    }
    cout<<k1<<k2<<k3<<k4;
    return 0;
}
