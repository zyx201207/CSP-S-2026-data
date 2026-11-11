#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool ck1(char a,char b){
    return a>='A'&&a<='C'&&b>='A'&&b<='C';
}
bool ck2(char a,char b){
    return a>='D'&&a<='F'&&b>='D'&&b<='F';
}
bool ck3(char a,char b){
    if((a=='C'&&b=='D')||(a=='D'&&b=='C')) return 0;
    LL k=abs(a-b);
    return k==1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }

    if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else{
        cout<<"000";
        return 0;
    }

    char a=s1[2],b=s2[2];
    if((s1[0]==s2[0]&&s1[1]==s2[1])&&(ck1(a,b)||ck2(a,b))) cout<<1;
    else{
        cout<<"00";
        return 0;
    }

    if((s1[0]==s2[0]&&s1[1]==s2[1])&&ck3(a,b)) cout<<1;
    else cout<<0;
    return 0;
}
