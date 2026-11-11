#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >>c1>>s1>>c2>>s2;
    string ans="";

    if(c1==c2)  ans+="1";
    else{
        cout <<"0000"<<endl;
        return 0;
    }

    string paiR="",paiX="";
    paiR=s1[0]+s1[1];
    paiX=s2[0]+s2[1];
    if(paiR==paiX)  ans+="1";
    else{
        cout <<ans<<"000"<<endl;
        return 0;
    }

    char t1=s1[2],t2=s2[2];
    if(((t1=='C' && t2=='D') || (t1=='D' && t2=='C')) || ((t1>='A' && t1<='C') && (t2>='D' && t2<='F')) || ((t2>='A' && t2<='C') && (t1>='D' && t1<='F'))){
        cout <<ans<<"00"<<endl;
        return 0;
    }
    else  ans+="1";

    if(t2==t1+1 || t1==t2+1)  ans+="1";
    else{
        cout <<ans<<"0"<<endl;
        return 0;
    }

    cout <<ans;
    return 0;
}
