#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    int c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(s1[2]=='F'){
        s1[2]=='E';
    }
    if(s2[2]=='F'){
        s2[2]='E';
    }
    bool f1=(c1==c2);
    bool f2=f1&(s1[0]==s2[0])&(s1[1]==s2[1]);
    bool f3=f2&(((s1[2]>='D'&&s1[2]<='E')&&(s2[2]>='D'&&s2[2]<='E'))||((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')));
    bool f4=f3&&(abs(s1[2]-s2[2])==1&&!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')));
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
