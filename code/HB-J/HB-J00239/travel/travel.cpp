#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
    cin>>s1>>s2>>s3>>s4>>s5>>s6>>s7>>s8>>s9>>s10;
    bool c,d,e,f;
    int i=int(s1)*10+int(s2),j=int(s6)*10+int(s7);
    if(i==j) c=true;
    else c=false;
    int n=int(s3)*10+int(s4),m=int(s8)*10+int(s9);
    if (c==false) d=false;
    else if(n==m) d=true;
    else d=false;
    if(d==false) e=false;
    else if(s5>='D' && s10>='D') e=true;
    else if(s5<='C' && s10<='C') e=true;
    else e=false;
    if(e==false || d==false) f=false;
    else if(s5=='A' && s10=='B' || s5=='B' && s10=='C'||s10=='A' && s5=='B' || s10=='B' && s5=='C'|| s5=='D' && s10=='F' || s10=='D' && s5=='F') f=true;
    else f=false;
    cout<<c<<d<<e<<f;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
