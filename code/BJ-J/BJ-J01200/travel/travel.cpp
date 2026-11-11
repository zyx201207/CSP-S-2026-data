#include<bits/stdc++.h>
using namespace std;
int c1,r1,c2,r2;
char s1,s2;
bool get(char s){
    return s=='A'||s=='B'||s=='C';
}
int main(){
    freopen("travel.in","r",stdin),freopen("travel.out","w",stdout),
    scanf("%d %d%c %d %d%c",&c1,&r1,&s1,&c2,&r2,&s2);
    if(c1!=c2)cout<<"0000";
    else if(r1!=r2)cout<<"1000";
    else if(get(s1)!=get(s2))cout<<"1100";
    else if(abs(s1-s2)!=1)cout<<"1110";
    else cout<<"1111";
    return 0;
}