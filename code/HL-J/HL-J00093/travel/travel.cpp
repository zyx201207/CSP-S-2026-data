#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<1;
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    string word1="";
    string word2="";
    for(int i=0;i<2;i++){
        word1+=s2[i];
        word2+=s4[i];
    }
    if(word1==word2){
        cout<<1;
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if((s2[2]>='D' && s4[2]>='D') || (s2[2]<='C' && s4[2]<='C')){
        cout<<1;
    }else{
        cout<<0;
        cout<<0;
        return 0;
    }
    if(s2[2]-s4[2]==1 || s2[2]-s4[2]==-1 || (s2[2]=='D' && s4[2]=='F') || (s2[2]=='F' && s4[2]=='D')){
        cout<<1;
    }else{
        cout<<0;
        return 0;
    }
    return 0;
}
