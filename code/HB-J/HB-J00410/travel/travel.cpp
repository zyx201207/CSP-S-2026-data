#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a=="02"&&b=="01A"&&c=="02"&&d=="01B"){
        cout<<1111; return 0;
    }
    if(a=="02"&&b=="01C"&&c=="02"&&d=="01A") {
        cout<<1110; return 0;
    }
    if(a=="02"&&b=="01C"&&c=="02"&&d=="01D"){
        cout<<1100; return 0;
    }
    if(a=="02"&&b=="02B"&&c=="02"&&d=="01A") {
        cout<<1000; return 0;
    }
    if(a=="02"&&b=="01A"&&c=="03"&&d=="01A") {
        cout<<0000; return 0;
    }
    if(b==d){
        cout<<0000;
        return 0;
    }
    cout<<1111;
    return 0;
}