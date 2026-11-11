#include<bits/stdc++.h>
using namespace std;
bool check2(string s1,string s2){
    char t1=s1[2],t2=s2[2];
    if(t1=='A'&&t2=='B')return true;
    if(t1=='B'&&t2=='A')return true;
    if(t1=='B'&&t2=='C')return true;
    if(t1=='C'&&t2=='B')return true;
    if(t1=='D'&&t2=='F')return true;
    if(t2=='D'&&t1=='F')return true;
    return false;
}
bool check(string s1,string s2){

    string r1="";
    string r2="";
    for(int i=0;i<2;i++){
        r1+=s1[i];
        r2+=s2[i];
    }
    if(r2!=r1)return false;
    return true;
}
bool check3(string s1,string s2){
    char t1=s1[2],t2=s2[2];
    if('A'<=t1&&'C'>=t1&&'A'<=t2&&'C'>=t2)return true;
    if('D'<=t1&&'F'>=t1&&'D'<=t2&&'F'>=t2)return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<1;
        if(check(s2,s4)){
            cout<<1;
            if(check3(s2,s4)){
                cout<<1;
                if(check2(s2,s4)){
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<0<<0;
        }
        else  cout<<0<<0<<0;
    }else cout<<0<<0<<0<<0;
    return 0;
}