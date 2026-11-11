#include <iostream>
#include <bits/types.h>
int a,b,c,d;
char q,w,p1,p2,e,r;
std::string z,x;
int main(){
    freopen(travel.in,stdin,r);
    freopen(travel.out,stdout,w);
    std::cin>>a>>z>>b>>x;
    if(a==b){
        std::cout<<1;
    }
    if(a!=b){
        std::cout<<0<<0<<0<<0;
        return 0;
    }
    p1=z[0];
    p2=x[0];
    q=z[1];
    w=x[1];
    if(q==w&&p1==p2){
        std::cout<<1;
    }
    else{
        std::cout<<0;
    }
    e=z[2];
    r=x[2];
    if('A'<=e&&e<='C')    c=1;
    else    c=0;
    if('A'<=r&&r<='C')    d=1;
    else    d=0;
    if(c==d)    std::cout<<1;
    else{
        std::cout<<0<<0;
        return 0;
    }
    if('A'==r)    c=1;
    if('B'==r)    c=2;
    if('C'==r)    c=3;
    if('D'==r)    c=4;
    if('F'==r)    c=5;
    if('A'==e)    d=1;
    if('B'==e)    d=2;
    if('C'==e)    d=3;
    if('D'==e)    d=4;
    if('F'==e)    d=5;
    if(c--==d||d--==c&&c--!=3&&d--!=3)    std::cout<<1;
    else    std::cout<<0;
    return 0;
}
