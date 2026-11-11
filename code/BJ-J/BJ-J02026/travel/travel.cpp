#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    std::string a,b,c,d,e,f,g,h;
    std::cin>>a>>b>>c>>d;
    e=b[0]+b[1];
    f=d[0]+d[1];
    g=b[2];
    h=d[2];
    if(a==c){
        std::cout<<1;
    }
    else{
        std::cout<<0;
    }
    if(a==c&&e==f){
        std::cout<<1;
    }
    else{
        std::cout<<0;
    }
    if(a==c&&e==f&&g<="C"&&h<="C"||g>="D"&&h>="D"){
        std::cout<<1;
    }
    else{
        std::cout<<0;
    }
    if(a==c&&e==f&&g=="A"&&h=="B"||g=="B"&&h=="A"||g=="B"&&h=="C"||g=="C"&&h=="B"||g=="D"&&h=="E"|g=="E"&&h=="D"){
        std::cout<<1;
    }
   else{
        std::cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}