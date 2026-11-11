#include<bits/stdc++.h>
using namespace std;
long long a,b;
string s1,s2;
int f1,f2;
int pos1,pos2,k1,k2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;

    pos1=s1[0];
    pos2=s1[1];
    k1=s2[0];
    k2=s2[1];

    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        f1=1;
    }else{
        f1=2;
    }
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
        f2=1;
    }else{
        f2=2;
    }
    if(a!=b){
        cout<<"0000";
        return 0;
    }else if(pos1!=k1||pos2!=k2){
        cout<<"1000";
    }else if(f1!=f2){
        cout<<"1100";
    }else if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
        cout<<"1111";
    }else{
        cout<<"1110";
    }
    return 0;
}

