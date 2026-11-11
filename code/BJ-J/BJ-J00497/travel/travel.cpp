#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a;
struct ticket{
    int c;
    string s;
};
ticket t1;
ticket t2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>t1.c>>t1.s>>t2.c>>t2.s;
    if(t1.c!=t2.c){
        cout<<0000;
    }else{
        cout<<1;
        if(t1.s.substr(0,2)!=t2.s.substr(0,2)){
            cout<<000;
        }else{
            cout<<1;
            string a=t1.s.substr(2,3),b=t2.s.substr(2,3);
            if(!((a=="A"&&b=="B")||(a=="A"&&b=="C")||(a=="B"&&b=="A")||(a=="B"&&b=="C")||(a=="C"&&b=="A")||(a=="C"&&b=="B")||(a=="D"&&b=="E")||(a=="E"&&b=="D"))){
                cout<<00;
            }else{
                cout<<1;
                if(!(a=="A"&&b=="B")||(a=="B"&&b=="A")||(a=="B"&&b=="C")||(a=="C"&&b=="B")||(a=="D"&&b=="E")||(a=="E"&&b=="D")){
                    cout<<0;
                }else{
                    cout<<1;
                }
            }
        }
    }
    return 0;
}
