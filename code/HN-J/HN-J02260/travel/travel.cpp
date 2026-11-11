#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s,s1,t,t1,ss,tt;
bool f=0,f1,f2,f3;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>s1>>t>>t1;
    ss+=s1[0],tt+=t1[0];
    ss+=s1[1],tt+=t1[1];
    if(((s1[2]>='A'&&s1[2]<='C')&&(t1[2]>='A'&&t1[2]<='C'))||((s1[2]=='D'||s1[2]=='F')&&(t1[2]=='D'||t1[2]=='F'))){
       f=1;
       }

    if(s==t){
            f1=1;
        cout<<1;
    }else{
    cout<<0;
    }
    if(ss==tt&&f1==1){
        f2=1;
        cout<<1;
    }else{
    cout<<0;
    }
    if((ss==tt&&f==1&&f1==1)){
        f3=1;
        cout<<1;
    }else{
    cout<<0;
    }

    if((((s1[2]+1==t1[2]&&t1[2]!='D'&&f1==1&&f2==1)
        ||(s1[2]-1==t1[2]&&t1[2]!='C'&&f1==1&&f2==1))
        ||((t1[2]=='F'&&s1[2]=='D'&&f1==1&&f2==1)
        ||(t1[2]=='D'&&s1[2]=='F'&&f1==1&&f2==1)))){
       cout<<1;
       }else{
       cout<<0;
       }
    return 0;
}
