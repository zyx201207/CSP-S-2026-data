#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int r,x;
    string s1,s2,a,b;
    cin>>r>>s1>>x>>s2;
    if(s1[2]>=65&&s1[2]<=67){
        a="L";
    }
    else{
        a="R";
    }
    if(s2[2]>=65&&s2[2]<=67){
        b="L";
    }
    else{
        b="R";
    }
    if(r==x){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(r==x&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }else{
        cout<<0;
    }
    if(r==x&&s1[0]==s2[0]&&s1[1]==s2[1]&&a==b){
        cout<<1;
    }else{
        cout<<0;
    }
    if(r==x&&s1[0]==s2[0]&&s1[1]==s2[1]&&a==b&&(s1[2]==s2[2]+1||s1[2]==s2[2]-1)){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
