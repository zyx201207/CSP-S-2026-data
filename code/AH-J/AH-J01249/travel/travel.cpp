#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check1(string x,string y){
    if(x[0]==y[0]&&x[1]==y[1]){
        if(x[2]=='D'&&y[2]=='F'){
            return 1;
        }else if(x[2]=='F'&&y[2]=='D'){
            return 1;
        }else if(x[2]=='C'&&y[2]=='B'){
            return 1;
        }else if(x[2]=='B'&&y[2]=='C'||x[2]=='B'&&y[2]=='A'){
            return 1;
        }else if(x[2]=='A'&&y[2]=='B'){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}
bool check2(string x,string y){
    if(x[0]==y[0]&&x[1]==y[1]){
        if(x[2]=='D'&&y[2]=='F'){
            return 1;
        }else if(x[2]=='F'&&y[2]=='D'){
            return 1;
        }else if(x[2]=='C'&&y[2]=='B'||x[2]=='C'&&y[2]=='A'){
            return 1;
        }else if(x[2]=='B'&&y[2]=='C'||x[2]=='B'&&y[2]=='A'){
            return 1;
        }else if(x[2]=='A'&&y[2]=='B'||x[2]=='A'&&y[2]=='C'){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&check2(s1,s2)){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&check1(s1,s2)){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
