#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>t1>>t2;
    long long q=(s1[0]-'0')*10+(s1[1]-'0');
    long long p=(t1[0]-'0')*10+(t1[1]-'0');
    if(q==p){
        cout<<1;
    }else{
        cout<<0;
    }
    long long l1=(s2[0]-'0')*10+s2[1]-'0';
    long long l2=(t2[0]-'0')*10+t2[1]-'0';
    if(q==p && l1==l2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(q==p && l1==l2 && ((s2[2]-'A')<3 && (t2[2]-'A')<3 || (s2[2]-'A')>2 && (t2[2]-'A')>2)){
        cout<<1;
    }else{
        cout<<0;
    }
    if(q==p && l1==l2 && ((s2[2]-'A')<3 && (t2[2]-'A')<3 || (s2[2]-'A')>2 && (t2[2]-'A')>2) && (((s2[2]-'A')-(t2[2]-'A')==1)||(s2[2]-'A')-(s2[2]-'A')==1)){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
