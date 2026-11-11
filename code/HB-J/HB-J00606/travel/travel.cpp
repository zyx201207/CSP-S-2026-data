#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1[4],c2,s2[4];
    int a,b,c,d;
    cin>>c1>>s1[4]>>c2>>s2[4];
    if(c1==c2){
       a==1;
    }else{
       a==0;
    }
    cout<<a
    if(s1[1]==s2[1]||s1[2]==s2[2]){
        b==1;
    }else{
        b==0;
    }
    cout<<b;
    if(s1[3]=='A'||s2[3]=='B'&&s1[3]=='B'||s2[3]=='C'&&s1[3]=='D'||s2[3]=='F'&&s1[3]=='B'||s2[3]=='A'&&s1[3]=='C'||s2[3]=='B'&&s1[3]=='F'||s2[3]=='D'){
        c==1,d==1;
    }else if(s1[3]=='A'||s2[3]=='C'&&s1[3]=='A'||s2[3]=='D'&&s1[3]=='C'||s2[3]=='A'&&s1[3]=='D'||s2[3]=='A') {
        c==1,d==0;
    }else c==0,d==0;
    cout<<c<<d;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
