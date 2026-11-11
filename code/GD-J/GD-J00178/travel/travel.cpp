#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    int n=s1.size()-1;
    int m=s2.size()-1;
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2){
       int num1=0;
       int num2=0;
       for(auto ch:s1){
           if(ch>='0'&&ch<='9') num1=num1*10+ch-'0';
       }
       for(auto ch:s2){
           if(ch>='0'&&ch<='9') num2=num2*10+ch-'0';
       }
       if(num1==num2) cout<<1;
       else cout<<0;
    }
    else cout<<0;
    if(c1==c2){
       int num1=0;
       int num2=0;
       for(auto ch:s1){
           if(ch>='0'&&ch<='9') num1=num1*10+ch-'0';
       }
       for(auto ch:s2){
           if(ch>='0'&&ch<='9') num2=num2*10+ch-'0';
       }
       if(num1==num2){
          bool p1,p2;
          if(s1[n]=='F'||s1[n]=='D') p1=1;
          else p1=0;
          if(s2[n]=='F'||s2[n]=='D') p2=1;
          else p2=0;
          if(p1==p2) cout<<1;
          else cout<<0;
       }
       else cout<<0;
    }
    else cout<<0;
    if(c1==c2){
       int num1=0;
       int num2=0;
       for(auto ch:s1){
           if(ch>='0'&&ch<='9') num1=num1*10+ch-'0';
       }
       for(auto ch:s2){
           if(ch>='0'&&ch<='9') num2=num2*10+ch-'0';
       }
       if(num1==num2){
          bool p1,p2;
          if(s1[n]=='F'||s1[n]=='D') p1=1;
          else p1=0;
          if(s2[m]=='F'||s2[m]=='D') p2=1;
          else p2=0;
          if(p1==p2){
             if(p1==1){
                if((s1[n]=='F'&&s2[m]=='D')||(s1[n]=='D'&&s2[m]=='F')) cout<<1;
                else cout<<0;
             }
             else{
                if((s1[n]=='C'&&s2[m]=='B')||(s1[n]=='B'&&s2[m]=='A')||(s2[m]=='C'&&s1[n]=='B')||(s2[m]=='B'&&s1[n]=='A')) cout<<1;
                else cout<<0;
             }
          }
          else cout<<0;
       }
       else cout<<0;
    }
    else cout<<0;
    return 0;
}

