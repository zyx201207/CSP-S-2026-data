#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;

    bool h=0;
    if(c1==c2){
            printf("1");
            h=1;
    }else{
        printf("0");
    }

    bool f1=0;
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&h){
        f1=1;
        printf("1");
    }else{
        printf("0");
    }

    bool f2=0,f3=0;
    if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))f2=1;
    else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))f3=1;

    if(f1&&(f2||f3))printf("1");
    else printf("0");

    ll a,b;
    if(s1[2]=='A')a=1;
    else if(s1[2]=='B')a=2;
    else if(s1[2]=='C')a=3;

    if(s2[2]=='A')b=1;
    else if(s2[2]=='B')b=2;
    else if(s2[2]=='C')b=3;

    if(f3)printf("1");
    else if(f1&&abs(a-b)==1)printf("1");
    else printf("0");
    return 0;
}
