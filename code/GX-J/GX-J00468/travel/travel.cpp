#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    char a[4];
    for(int i=0;i<4;i++){
        a[i]='0';
    }
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a[0]='1';
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        a[1]='1';
    }
    if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'&&s1[0]==s2[0]&&s1[1]==s2[1]){
        a[2]='1';
    }
    if('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'&&s1[0]==s2[0]&&s1[1]==s2[1]){
        a[2]='1';
    }
    if(s1[2]+1==s2[2]&&s2[2]-1==s1[2]&&'A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'&&s1[0]==s2[0]&&s1[1]==s2[1]){
        a[3]='1';
    }
    if(s1[2]-1==s2[2]&&s2[2]+1==s1[2]&&'D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'&&s1[0]==s2[0]&&s1[1]==s2[1]){
        a[3]='1';
    }
    for(int i=0;i<4;i++){
        cout<<a[i];
    }
    return 0;
}
