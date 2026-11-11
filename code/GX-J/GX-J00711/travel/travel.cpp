#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
int f,f1,f2,f3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>s1>>s2>>s3;
    for(int i=0;i<2;i++){
        if(s[i]!=s2[i]){
            f=1;
        }
    }
    if(f==1){
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    cout<<1;
    for(int i=0;i<2;i++){
        if(s1[i]!=s3[i]){
            f1=1;
        }
    }
    if(f1==1){
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    cout<<1;
    if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s3[2]=='A'||s3[2]=='B'||s3[2]=='C')&&s1[2]!=s3[2]){
        cout<<1;
    }else if((s1[2]=='D'&&s3[2]=='F')||(s1[2]=='F'&&s3[2]=='D')){
        cout<<1;
    }else{
        cout<<0;
        cout<<0;
        return 0;
    }
    if(s1[2]=='A'&&s3[2]=='B'){
        cout<<1;
        return 0;
    }else if(s1[2]=='B'&&(s3[2]=='A'||s3[2]=='C')){
        cout<<1;
        return 0;
    }else if(s1[2]=='C'&&s3[2]=='B'){
        cout<<1;
        return 0;
    }else if(s1[2]=='F'&&s3[2]=='D'){
        cout<<1;
        return 0;
    }else if(s1[2]=='D'&&s3[2]=='F'){
        cout<<1;
        return 0;
    }else if(s3[2]=='A'&&s1[2]=='B'){
        cout<<1;
        return 0;
    }else if(s3[2]=='B'&&(s1[2]=='A'||s1[2]=='C')){
        cout<<1;
        return 0;
    }else if(s3[2]=='C'&&s1[2]=='B'){
        cout<<1;
        return 0;
    }else if(s3[2]=='F'&&s1[2]=='D'){
        cout<<1;
        return 0;
    }else if(s3[2]=='D'&&s1[2]=='F'){
        cout<<1;
        return 0;
    }else{
        cout<<0;
        return 0;
    }
    return 0;
}
