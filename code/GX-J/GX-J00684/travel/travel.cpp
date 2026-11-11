#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,C,S;
    int a=0,b=0,e=0,d=0;
    cin>>c>>s>>C>>S;
    if(c==C){
       a++;
    if(s[0]==S[0]&&s[1]==S[1]){
        b++;
    if(s[3]+S[3]=='C'+'D'){
        e=0;
    }
    else{
        e++;
    }
    if(e==0){
        d=0;
    if(s[3]-1==S[3]||S[3]-1==s[3]){
            d++;
            }
        }
    }
    }
cout<<a<<b<<e<<d;
return 0;
}
