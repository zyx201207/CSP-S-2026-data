#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    char z1,z2;
    int r,x,a,b;
    cin>>r>>x>>z1>>z2>>a>>b;
    z1=z1+42;
    z2=z2+42;
    z1=z1%100;
    z2=z2%100;

    if(a==01||a==17){
        cout<<0;
    }else if(a==b){
        else if(z1==z2){
            if(r==x+1||r==x-1){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
                cout<<0;
            }

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
