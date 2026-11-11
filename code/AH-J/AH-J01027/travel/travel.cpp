#include "bits/stdc++.h"
#define int long long
using namespace std;
string c1,c2,s1,s2;
string ans;
bool check_row(char x,char y){
    if(x=='A' || x=='B' || x=='C'){
        return (y=='A' || y=='B' || y=='C');
    }else if(x=='D' || x=='F'){
        return (y=='D' || y=='F');
    }
}
bool check(char x,char y){
    if(x=='A') return (y=='B');
    else if(x=='B') return (y=='A' || y=='C');
    else if(x=='C') return (y=='B');
    else if(x=='D') return (y=='F');
    else return (y=='D');
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        ans=ans+"0000";
    }else{
        ans=ans+"1";
        string p1=s1.substr(0,2),p2=s2.substr(0,2);
        if(p1!=p2){
            ans=ans+"000";
        }else{
            ans=ans+"1";
            char a=s1[2],b=s2[2];
            if(!check_row(a,b)){
                ans=ans+"00";
            }else{
                ans=ans+"1";
                if(check(a,b)){
                    ans=ans+"1";
                }else{
                    ans=ans+"0";
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
