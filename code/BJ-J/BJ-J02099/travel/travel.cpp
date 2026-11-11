#include <iostream>
using namespace std;
bool f1(char c1,char c2){
    if (c1=='A'||c1=='B'||c1=='C'){
        if (c2=='A'||c2=='B'||c2=='C'){
            return true;
        }else{
            return false;
        }
    }else{
        if (c2=='D'||c2=='F'){
            return true;
        }else{
            return false;
        }
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool b1=false,b2=false,b3=false,b4=false;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2){
        b1=true;
    }
    if (b1&&s1[0]==s2[0]&&s1[1]==s2[1]){
        b2=true;
    }
    if (b2){
        b3=f1(s1[2],s2[2]);
    }
    if (b3){
        if (s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'){
            b4=true;
        }else if (s1[2]=='D'||s1[2]=='F'){
            b4=true;
        }
    }
    cout<<b1<<b2<<b3<<b4;
    return 0;
}
