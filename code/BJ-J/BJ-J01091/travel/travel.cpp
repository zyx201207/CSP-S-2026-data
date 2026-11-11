#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

typedef long long ll;
string c1,s1,c2,s2;
void pow1(string c1,string s1,string c2,string s2){
    string a1,a2,b1,b2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return ;
    }
    a1=s1[0];
    a2=s2[0];
    a1+=s1[1];
    a2+=s2[1];
    if(a1==a2){
        cout<<"1";
    }else{
        cout<<"000";
        return ;
    }
    if(s1[2]>='A'&&s1[2]<='C'){
        b1=1;
    }else{
        b1=2;
    }
    if(s2[2]>='A'&&s2[2]<='C'){
        b2=1;
    }else{
        b2=2;
    }
    b1+=s2[2];
    b2+=s2[2];
    if(b1[0]==b2[0]){
        cout<<"1";
        if(b1[0]==2){
            cout<<"1";
        }else if(b1[1]=='B'||b2[1]=='B'){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }else{
        cout<<"00";
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    pow1(c1,s1,c2,s2);
    return 0;
}

