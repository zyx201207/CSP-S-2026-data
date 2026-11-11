#include<iostream>
#include<cstring>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m,x=0,y=0;
    char c,d,e,f;
    cin>> n;
    for(int i=1;i<=2;i++){
        cin>> c;
        x=x*10+(c-'0');
    }
    cin>> c;
    if(c<='C') e='1';
    else e='2';
    cin>> m;
    for(int i=1;i<=2;i++){
        cin>> d;
        y=y*10+(d-'0');
    }
    cin>> d;
    if(d<='C') f='1';
    else f='2';
    if(n!=m){
        cout<< "0000";
        return 0;
    }
    cout<< 1;
    if(x!=y){
        cout<< "000";
        return 0;
    }
    cout<< 1;
    if(e!=f){
        cout<< "00";
        return 0;
    }
    cout<< 1;
    if(c-d==1 || c-d==-1) cout<< 1;
    else cout<< 0;
    return 0;
}
