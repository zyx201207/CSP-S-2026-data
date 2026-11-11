
#include<bits/stdc++.h>
using namespace std;
bool isside(string s1,string s2){
    char a=s1[2],b=s2[2];
    if(a=='C'&&b=='D'||a=='D'&&b=='C') return false;
    if(a-b==1) return true;
    return false;
}
bool fun(char a,char b){
    if('A'<=a&&a<='C'&&'A'<=b&&b<='C'){
        return true;
    }
    if('D'<=a&&a<='F'&&'D'<=b&&b<='F'){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    if(a==b){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(s1<=s2) swap(s1,s2);
    int c=(s1[0]-'0')*10+s1[1]-'0';
    int d=(s2[0]-'0')*10+s2[1]-'0';
    if(c==d){//the same col
        cout<<1;
        char x=s1[2],y=s2[2];
        //cout<<x<<' '<<y;
        if(fun(x,y)){
                cout<<1;
            if(isside(s1,s2)==true){
                cout<<1;
            }else{
                cout<<0;
                return 0;
            }
        }else{
            cout<<"00";
            return 0;
        }
    }
    else{// not the same col
        cout<<"000";
        return 0;
    }
    return 0;
}
//good,well done,army
//2026.10.31 9:48
//fully tested
//9:55
