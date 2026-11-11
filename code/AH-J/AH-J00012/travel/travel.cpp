#include<iostream>
using namespace std;
bool func(char x,char y){
    return x=='A'&&y=='B'||x=='A'&&y=='C'||x=='B'&&y=='C'||x=='D'&&y=='F';
}
bool check(char x,char y){
    return x=='A'&&y=='B'||x=='B'&&y=='C'||x=='D'&&y=='F';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<"1";
            char x=s1[2],y=s2[2];
            if(func(x,y)||func(y,x)){
                cout<<"1";
                if(check(x,y)||check(y,x))cout<<"1";
                else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
