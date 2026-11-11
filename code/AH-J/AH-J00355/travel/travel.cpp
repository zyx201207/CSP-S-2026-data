#include<bits/stdc++.h>

using namespace std;
int c1,c2;
string s,ss;
int l1,l2;
char s1,s2;
void gaster(){
    l1=int(s[0]-'0')*int(10)+int(s[1]-'0');
    s1=s[2];
    l2=int(ss[0]-'0')*int(10)+int(ss[1]-'0');
    s2=ss[2];
}
bool ch1(){
    if(('A'<=s1&&s1<='C')&&('A'<=s2&&s2<='C'))return 1;
    if(('D'<=s1&&s1<='F')&&('D'<=s1&&s1<='F'))return 1;
    return 0;
}
bool ch2(){
    int x=(s1-s2);
    if(x==1||x==-1)return 1;
    if((s1=='D'&&s2=='F')||(s1=='F'&&s2=='D'))return 1;
    return 0;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1;
    cin>>s;
    cin>>c2;
    cin>>ss;
    gaster();
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&l1==l2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&l1==l2&&ch1()==1){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&l1==l2&&ch1()==1&&ch2()==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
