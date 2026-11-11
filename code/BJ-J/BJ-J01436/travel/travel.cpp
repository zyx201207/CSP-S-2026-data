#include <iostream>
#include <string>
namespace std{};
int a,c;
string b,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    std::cin>>a>>b>>c>>d;
    if(a==c){
        std::cout<<1;
    }
    else{
        std::cout<<0;
    }
    if (b[0]==d[0]&&b[1]==b[1]){
        std::cout<<1;
    }
    else{
        std::cout<<0;
    }
    if (b[2]=="A"){
        if (d[2]=="B"){
            std::cout<<1;
        }
        else{
            std::cout<<0;
        }
    }
    else if(b[2]=="B"){
        if (d[2]=="A"||d[2]=="C"){
            std::cout<<1;
        }
        else{
            std::cout<<0;
        }
    }
    else if (b[2]=="C"){
        if (d[2]=="B"){
            std::cout<<1;
        }
        else{
            std::cout<<0;
        }
    }
    else if (b[2]=="D"){
        if (d[2]=="F"){
            std::cout<<1;
        }
        else{
            std::cout<<0;
        }
    }
    else if (b[2]=="F"){
        if (d[2]=="D"){
            std::cout<<1;
        }
        else{
            std::cout<<0;
        }
    }
    return 0;
}