#include<bits/stdc++.h>

std::string c1,s1,c2,s2,p1,p2;
char z1,z2;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    std::cin>>c1>>s1>>c2>>s2;
    if(c1==c2)std::cout<<1;
    else std::cout<<0;
    for(int i=0;i<=1;i++){
        p1+=s1[i];
        p2+=s2[i];
    }
    if(p1==p2)std::cout<<1;
    else std::cout<<0;
    z1=s1[2];
    z2=s2[2];
    if('A'<=z1 && z1<='C' && 'A'<=z2 && z2<='C' || z1=='D' && z2=='E' || z1=='E' && z2=='D'){
        std::cout<<1;
        if(z1+1==z2 || z1-1==z2)std::cout<<1;
        else std::cout<<0;
    }
    else{
        std::cout<<0<<0;
    }

return 0;
}
