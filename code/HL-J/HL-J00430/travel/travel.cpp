#include<bits/stdc++.h>
using namespace std;
struct seat{
    int a;
    char s;
};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c1,c2;
	seat s1,s2;
    cin>>c1>>s1.a>>s1.s>>c2>>s2.a>>s2.s;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(s1.a==s2.a){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if(s1.s<='C'&&s2.s<='C'&&s1.s>='A'&&s2.s>='A'){
        cout<<"1";
        if(s1.s-s2.s==1||s2.s-s1.s==1){
            cout<<"1";
        }else{
            cout<<"0";
            return 0;
        }
    }else if(s1.s=='D'&&s2.s=='F'){
        cout<<"11";
        return 0;
    }else if(s1.s=='F'&&s2.s=='D'){
        cout<<"11";
        return 0;
    }else{
        cout<<"00";
        return 0;
    }

    return 0;
}
