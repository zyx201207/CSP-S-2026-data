#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r1,r2,s1,s2;
    cin>>r1>>r2>>s1>>s2;
    if(r1==s1) printf("1");
    else{
        printf("0000");
        return 0;
    }
    if(r2[0]==s2[0]&&r2[1]==s2[1]) printf("1");
    else{
        printf("000");
        return 0;
    }
    if((r2[2]=='A'||r2[2]=='B'||r2[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) printf("1");
    else if((r2[2]=='D'||r2[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) printf("1");
    else{
        printf("00");
        return 0;
    }
    if((r2[2]=='A'||r2[2]=='B'||r2[2]=='C')&&(r2[2]+1==s2[2]||r2[2]-1==s2[2])) printf("1");
    else if(r2[2]=='D'||r2[2]=='F') printf("1");
    else printf("0");
    return 0;
}