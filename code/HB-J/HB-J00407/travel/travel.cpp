#include <bits/stdc++.h>
using namespace std;
bool judge(char w1,char w2){
    return (((w1>='A'&&w1<='C')&&(w2>='A'&&w2<='C'))||((w1>='D'&&w1<='E')&&(w2>='D'&&w2<='E')));
}
bool check(char w1,char w2){
    return (abs(int(w1-w2))==1)&&((w1!='D'&&w2!='C')||(w1!='C'&&w2!='D'));
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    string p1=s1.substr(0,2);
    string p2=s2.substr(0,2);
    char w1=s1[2];
    char w2=s2[2];
    if(w1=='F') w1='E';
    if(w2=='F') w1='E';

    if(c1==c2) cout<<"1";
    else cout<<"0";
    if(c1==c2&&p1==p2) cout<<"1";
    else cout<<"0";
    if(c1==c2&&p1==p2&&judge(w1,w2)) cout<<"1";
    else cout<<"0";
    if(c1==c2&&p1==p2&&judge(w1,w2)&&check(w1,w2)) cout<<"1";
    else cout<<"0";
    return 0;
}
