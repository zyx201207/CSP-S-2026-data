#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("travel1.in","r",stdin);
    freopen("travel.out","w",stdout);

    int n1,m1;
    char n2[5],m2[5];
    cin>>n1>>n2>>m1>>m2;

    char a=0,b=0,c=0,d=0;

    if(n1==m1){
        a=1;
        if(n2[0] == m2[0] && n2[1] == m2[1]){
            b=1;
            if(n2[2] <= "C" && m2[2] > "C" || m2[2] <= "C" && n2[2] > "C"){
                c=1;
                if(!(n2[2] == "A" && m2[2] == "C" || m2[2] == "A" && n2[2] == "C")){
                    d=1;
                }
            }
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
