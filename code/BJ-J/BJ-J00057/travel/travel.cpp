#include<iostream>
using namespace std;
int a,b,c,d;
char x,y;
bool pd1(char x,char y){
    if(x=='A' || x=='B' || x=='C'){
        if(y=='A' || y=='B' || y=='C'){
            return 1;
        }
    }else if(x=='D' || x=='F'){
        if(y=='D' || y=='F'){
            return 1;
        }
    }
    return 0;
}
bool pd2(char x,char y){
    if(x=='A'){
        if(y=='B'){
            return 1;
        }
    }
    if(x=='B'){
        if(y=='C' || y=='A'){
            return 1;
        }
    }
    if(x=='C'){
        if(y=='B'){
            return 1;
        }
    }
    if(x=='D'){
        if(y=='F'){
            return 1;
        }
    }
    if(x=='F'){
        if(y=='D'){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>x>>c>>d>>y;
    if(a==c){
        cout<<"1";
        if(b==d){
            cout<<"1";
            if(pd1(x,y)){
                cout<<"1";
                if(pd2(x,y)){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
