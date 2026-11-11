#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int m,n;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool a=0,b=0,c=1,d=0;
    if(c1==c2)a=1;
    m=s1[0]+s1[1];
    n=s2[0]+s2[1];
    if(m==n)b=1;
    if(s1[2]<='C'&&s2[2]>='D'||s1[2]>='D'&&s2[2]<='C'){
        c=0;
    }
    else{
        if(s1[2]-s2[2]==1||s2[2]-s1[2]==1||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')d=1;
    }
    if(a==0)cout<<"0000";
    else if(b==0)cout<<"1000";
    else if(c==0)cout<<"1100";
    else if(d==0)cout<<"1110";
    else cout<<"1111";
    return 0;
}
