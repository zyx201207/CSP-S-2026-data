#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,x2,j1,j2;
    cin>>x1>>j1>>x2>>j2;
    if(x1[0]==x2[0]&&x1[1]==x2[1]){
        cout<<1;
    }else{
        cout<<0;
    }
    if(j1[0]==j2[0]&&j1[1]==j2[1]){
        cout<<1;
    }else{
        cout<<0;
    }
    if((j1[2]>='A'&&j1[2]<='C'&&j2[2]>='A'&&j2[2]<='C')&&(j1[2]>='D'&&j1[2]<='E'&&j2[2]>='D'&&j2[2]<='E')){
        cout<<1;
    }else{
        cout<<0;
    }
    if(j1[3]==j2[3]+1||j1[3]==j2[3]-1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
