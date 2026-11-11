#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<"0000\n";
        return 0;
    }
    cout<<"1";
    string aa=a2.substr(0,2);
    string bb=b2.substr(0,2);
    if(aa!=bb){
        cout<<"000\n";
        return 0;
    }
    cout<<"1";
    char ax=a2[2];
    char bx=b2[2];
    if(!(ax<='C'&&bx<='C'||ax>='D'&&bx>='D')){
        cout<<"00\n";
        return 0;
    }
    cout<<"1";
    if(ax>bx) swap(ax,bx);
    if((int)ax-(int)bx!=1&&ax!='D'&&bx!='F'){
        cout<<"0\n";
        return 0;
    }
    cout<<"1\n";
}