#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1,c1,s2,c2;
    cin>>s1>>c1>>s2>>c2;
    string r1=c1.substr(0,2),r2=c2.substr(0,2);
    char t1=c1[2],t2=c2[2];
    if(s1==s2){cout<<"1";
        if(r1==r2){
            cout<<"1";
            if((t1>='A'&&t1<='C'&&t2>='A'&&t2<='C')||(t1>='D'&&t1<='E'&&t2>='D'&&t2<='E')){
                cout<<"1";
                if(t1=='A'&&t2=='B'||t1=='B'&&t2=='A'||t1=='B'&t2=='C'||t1=='C'&&t2=='B'||t1=='D'&&t2=='E'||t1=='E'&&t2=='D')cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";


}
