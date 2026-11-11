#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,s3,s4,s5,s6;
char s7,s8;
bool vis=false;
bool flag=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout) ;
    //cin
    cin>>c1>>s1>>c2>>s2;
    //One
    if(c1==c2){
        flag=true;
        cout<<1;
    }
    else{
        cout<<0;
    }
    int len=s1.size();
    for(int i = 0;i<len;i++){
        s3=s1[0];
        s4=s1[1];
        s5=s2[0];
        s6=s2[1];
        s7=s1[2];
        s8=s2[2];
    }
    //Two
    if(s3==s5&&s4==s6&&flag==true){
        vis=true;
        cout<<1;
    }
    else{
        cout<<0;
    }
    //Three
    if(s7=='A'&&s8=='B'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else if(s7=='B'&&s8=='C'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else if(s7=='A'&&s8=='C'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else if(s7=='D'&&s8=='F'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else if(s7=='B'&&s8=='A'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else if(s7=='C'&&s8=='B'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else if(s7=='C'&&s8=='A'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else if(s7=='F'&&s8=='D'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else cout<<0;
    //Four
    if(s7=='A'&&s8=='B'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else if(s7=='B'&&s8=='C'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else if(s7=='D'&&s8=='F'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else if(s7=='B'&&s8=='A'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else if(s7=='C'&&s8=='B'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else if(s7=='F'&&s8=='D'){
        if(vis==true) cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
