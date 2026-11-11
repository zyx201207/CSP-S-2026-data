#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
int cx,c1x;
int n,m;
string sx,s1x;
int sum1,sum2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>c1>>s1;
    string o="";
    for(int i=0;i<s.size()-1;i++){
        sum1=sum1*10+(s[i]-'0');
    }
    for(int i=0;i<s1.size()-1;i++){
        sum2=sum2*10+(s1[i]-'0');
    }

    if(c==c1){
        o+='1';
    }else{
        o+='0';
    }

    if(o[0]=='0'){
        o+='0';
    }else{
        sx=s.substr(0,2);
        s1x=s1.substr(0,2);
        if(sx==s1x){
            o+='1';
        }else{
            o+='0';
        }
    }

    if(o[1]=='0'){
        o+='0';
    }else{
        if(s[s.size()-1]=='F'||s[s.size()-1]=='D'){
            n=2;
        }else{
            n=1;
        }
        if(s1[s1.size()-1]=='F'||s1[s1.size()-1]=='D'){
            m=2;
        }else{
            m=1;
        }
        if(n==m){
            o+='1';
        }else{
            o+='0';
        }
    }
    char a=s[s.size()-1]-'0',b=s1[s1.size()-1]-'0';
    if(sx==s1x&&(a==b-1||a==b+1||a=='F'&&b=='D')){
       if(o[2]=='1'){
            o+='1';
       }else{
           o+='0';
       }
    }else if(sx!=s1x&&(sum1==sum2-1||sum1==sum2+1)){
        if(a==b){
            o+='1';
        }else{
            o+='0';
        }
    }else{
        o+='0';
    }
    cout<<o;





    return 0;
}
