#include<std.c++/h>
using namespace std;
int main(){
    feropen("travel.in","r","stdin");
    feropen("travel.out","w","stdout");
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==b){
        cout<<1;
         if(c==d){
             cout<<111;
         }
    }
    return 0
}
