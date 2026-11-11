#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,a2;
string b,b2;
LL d(string s){
    if(s[0]<='C') return 1;
    else if(s[0]=='D'||s[0]=='F') return 2;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>a2>>b2;
    string x=b.substr(0,2),y=b2.substr(0,2);
    string s=b.substr(2,1),s2=b2.substr(2,1);
    if(a==a2) printf("1");
    else printf("0");
    if(a==a2&&x==y) printf("1");
    else printf("0");
    if(a==a2&&x==y&&d(s)==d(s2)) printf("1");
    else printf("0");
    if(a==a2&&x==y&&d(s)==d(s2)){
        LL ad=d(s),bd=d(s2);
        char ch=s[0],ch2=s2[0];
        if(ad==1){
            if(labs(ch-ch2)==1) printf("1");
            else printf("0");
        }
        else if(ad==2&&bd==2) printf("1");
        else printf("0");
    }
    else printf("0");
    return 0;
}
