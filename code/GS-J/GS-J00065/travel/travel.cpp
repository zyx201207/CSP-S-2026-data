#include<bits/stdc++.h>
using namespace std;
struct myc{
    char a,b,c;
}s[2];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    cin>>c1>>s[1].a>>s[1].b>>s[1].c>>c2>>s[2].a>>s[2].b>>s[2].c;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if((c1==c2)&&(s[1].a==s[2].a&&s[1].b==s[2].b)){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if((c1==c2)&&(s[1].a==s[2].a&&s[1].b==s[2].b)&&((s[1].c=='A'||s[1].c=='B'||s[1].c=='C')&&(s[2].c=='A'||s[2].c=='B'||s[2].c=='C'))||((s[1].c=='F'||s[1].c=='D')&&(s[2].c=='F'||s[2].c=='D'))){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if((c1==c2)&&(s[1].a==s[2].a&&s[1].b==s[2].b)&&((((s[1].c=='F'&&s[2].c=='D')||(s[1].c=='D'&&s[2].c=='F'))||((s[1].c=='A'&&s[2].c=='B')||(s[1].c=='B'&&s[2].c=='A'))||((s[1].c=='B'&&s[2].c=='C')||(s[1].c=='C'&&s[2].c=='B'))))){
       cout<<"1";
    }
    else{
       cout<<"0";
    }
    return 0;
}
