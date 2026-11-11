#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string c1,s1,c2,s2;
    bool flag=0,flag1=0,flag2=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        flag2=1;
    }
    else cout<<0;
    if(flag2&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
        flag1=1;
    }
    else cout<<0;
    if(flag1&&('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
        cout<<1;
        flag=1;
    }
    else cout<<0;
    if(flag&&(s1[2]+1==s2[2]||s1[2]-1==s2[2])) cout<<1;
    else cout<<0;
    return 0;
}//g++ -O2 travel.cpp -o travel && ./travel