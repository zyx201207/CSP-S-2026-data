#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,s1,a2,s2;//01 01A 01 01B
    cin >> a1>>s1>>a2>>s2;
    bool q3=0,q4=0;
    if((a1[0]==a2[0])&&(a1[1]==a2[1]))cout<<"1";
    else{
        cout <<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout <<"1";//q2/  q3
        if((s1[2]>='A'&&s1[2]<='C') && s2[2]>='A'&&s2[2]<='C')
        { cout <<"1";  q3=1;}
        else if((s1[2]>='D'&&s1[2]<='F') && s2[2]>='D'&&s2[2]<='F')
        { cout <<"1";  q3=1;  q4=1;}
    }
    else cout <<"0";
    if(!q3)cout << "0";
    if(q3&&!q4){
        if(abs(s1[2]-s2[2])==1)cout<<"1";
        else cout <<"0";
    }else if(q3&&q4)cout << "1";
    else cout << "0" ;
    return 0;
}

