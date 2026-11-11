#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<map>
using namespace std;

int a,b,a1,b1,l[300];
char ca,cb;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    l[int('A')]=1;
    l[int('B')]=2;
    l[int('C')]=3;
    l[int('D')]=4;
    l[int('F')]=5;
    cin>>a>>a1>>ca>>b>>b1>>cb;
    if(a==b){
        cout<<1;
        if(a1==b1){
            cout<<1;
            if((ca<='C'&&cb<='C')||(ca>'C'&&cb>'C')){
                cout<<1;
                if(abs(l[int(ca)]-l[int(cb)])==1)cout<<1;
                else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
