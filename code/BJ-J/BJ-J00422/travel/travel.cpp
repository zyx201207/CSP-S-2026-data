#include <bits/stdc++.h>
using namespace std;
int calc(char let){
    if(let=='A'||let=='B'||let=='C') return 1;
    else return 2;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int rc,xc;
    int ra;
    char rb;
    cin>>rc;
    scanf("%d%c",&ra,&rb);
    int xa;
    char xb;
    cin>>xc;
    scanf("%d%c",&xa,&xb);
    if(rc==xc){
        cout<<1;
    }else{
        cout<<"0000"<<endl;
        return 0;
    }
    if(ra==xa){
        cout<<1;
    }else{
        cout<<"000"<<endl;
        return 0;
    }
    if(calc(rb)==calc(xb)){
        cout<<1;
    }else{
        cout<<"00"<<endl;
        return 0;
    }
    if(abs(rb-xb)==1){
        cout<<1<<endl;
    }else{
        cout<<"0"<<endl;
        return 0;
    }
    return 0;
}