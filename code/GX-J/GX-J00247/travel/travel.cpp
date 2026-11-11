#include<iostream>
#include<string>
using namespace std;
string a1,a2,c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>c1>>a2>>c2;
    if(a1[1]=a2[1]){
        cout<<1;
    }
    else {
        cout<<0;
    }
    if(c1[1]=c2[1])cout<<1;
    else cout<<0;
    if(c1[2]=c2[2]&&(c1[2]<='C'&&c2[2]<='C')||(c1[2]>'C'&&c2[2]>'C')){
            cout<<1;
            if(c1[2]==c2[2]+1||c1[2]==c2[2]-1)cout<<1;
            else cout<<0;
    }
    else cout<<0<<0;
    return 0;
}
