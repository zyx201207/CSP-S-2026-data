#include<iostream>
#include<string>
using namespace std;
long long a,b;
string a1,b1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a1>>b>>b1;
    if(a==b){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a1[0]==b1[0] && a1[1]==b1[1]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a1[2]<='C'&&b1[2]>='D'){
        cout<<0;
    }
    else{
        cout<<1;
    }
    if(a1[2]+1==b1[2]||a1[2]==b1[2]+1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
