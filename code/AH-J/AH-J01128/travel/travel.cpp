#include<bits/stdc++.h>
using namespace std;
int a,b;
string sa,sb;
inline int s_i(const string &x){
    return (x[0]-'0')*10+x[1]-'0';
}
inline bool che(char x,char y){
    return (x>='D'&&y>='D')||(x<='C'&&y<='C');
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>sa>>b>>sb;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    cout<<'1';
    if(s_i(sa)!=s_i(sb)){
        cout<<"000";
        return 0;
    }
    cout<<'1';
    if(!che(sa[2],sb[2])){
        cout<<"00";
        return 0;
    }
    cout<<'1';
    if(sb[2]>sa[2]){
        swap(sb[2],sa[2]);
    }
    cout<<(sa[2]-sb[2]==1?'1':'0');
    return 0;
}
