#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char e,f;
    cin>>a>>b>>e>>c>>d>>f;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    if(b!=d){
        cout<<"1000";
        return 0;
    }
    if('A'<=e&&e<='C'){
        if(f=='D'||f=='F'){
            cout<<"1100";
            return 0;
        }
    }
    if(e=='D'||e=='F'){
        if('A'<=f&&f<='C'){
            cout<<"1100";
            return 0;
        }
    }
    bool flag1=(e=='D'&&f=='F')||(e=='F'&&f=='D');
    bool flag2=(e=='A'&&f=='B')||(e=='B'&&f=='A');
    bool flag3=(e=='B'&&f=='C')||(e=='C'&&f=='B');
    if(flag1||flag2||flag3){
        cout<<"1111";
        return 0;
    }
    cout<<"1110";
    return 0;
}
