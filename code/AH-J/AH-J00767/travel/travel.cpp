#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool t=0;
    string s1,s2,id1,id2;
    cin>>s1>>id1>>s2>>id2;
    if(s1==s2){
        cout<<"1";
    }
    else if(s1!=s2){
        cout<<"0000";
        return 0;
    }
    for(LL i=0;i<=1;i++){
        if(id1[i]==id2[i]){
            t=1;
        }
        else{
            t=0;
        }
    }
    if(t==1){
        cout<<"1";
    }
    else if(t==0){
        cout<<"000";
        return 0;
    }
    LL p1=id1[2]-'0',p2=id2[2]-'0';
     if(id1[2]=='D',id2[2]=='F'){
        cout<<"11";
        return 0;
    }
    if(p1+1==p2&&id1[2]!='C'){
        cout<<"11";
        return 0;
    }
    if(p1-1==p2&&id1[2]!='D'){
        cout<<"11";
        return 0;
    }
    else if(p2<=p1+2&&p2>p1&&p1+1!=p2&&p2!='D'){
        cout<<"10";
        return 0;
    }
    else if(p1<=p2+2&&p1>p2&&p2+1!=p1&&p1!='D'){
        cout<<"10";
        return 0;
    }
    if(id1[2]=='D'&&id2[2]!='F'){
        cout<<"00";
        return 0;
    }
    else if(id2[2]=='D'&&id1[2]!='F'){
        cout<<"00";
        return 0;
    }
    return 0;

}
