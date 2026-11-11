#include<bits/stdc++.h>
using namespace std;
bool train(char m,char n){
    if(m<='C'&&n<='c') return 1;
    if(m>'C'&&n>'c') return 1;
    return 0;
}
bool near(char x,char y){
    if(x=='A'&&y=='B') return 1;
    if(x=='B'&&y=='A') return 1;
    if(x=='B'&&y=='C') return 1;
    if(x=='C'&&y=='B') return 1;
    if(x=='D'&&y=='F') return 1;
    if(x=='F'&&y=='D') return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(train(s2[2],s1[2])){
                cout<<1;
                cout<<near(s1[2],s2[2]);
            }
            else cout<<"00";
        }
        else {
            cout<<"000";
        }

    }
    else{
        cout<<"0000";
    }
    return 0;
}