#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string c1,s1,c2,s2;
bool check(char a,char b){
    if(a=='A'||a=='B'||a=='C')
        if(b=='A'||b=='B'||b=='C') return true;
        else return false;
    if(a=='D'||a=='F')
        if(b=='D'||b=='F') return true;
        else return false;
}
bool check2(char x,char y){
    if(x=='A') return y=='B';
    if(x=='B') return (y=='A')||(y=='C');
    if(x=='C') return y=='B';
    if(x=='D') return y=='F';
    if(x=='F') return y=='D';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else cout<<"1";
    string k1=s1.substr(0,2),k2=s2.substr(0,2);
    if(k1!=k2){
        cout<<"000";
        return 0;
    }
    else cout<<"1";
    char a1=s1[2],a2=s2[2];
    if(check(a1,a2))cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if(check2(a1,a2)) cout<<"1";
    else cout<<"0";
    return 0;
}
