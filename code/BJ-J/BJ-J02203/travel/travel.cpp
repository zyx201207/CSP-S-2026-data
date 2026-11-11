#include<bits/stdc++.h>
using namespace std;
bool check_t(char a,char b){
    return ((a>='A'&&a<='C')&&(b>='A'&&b<='C'))||((a>='D'&&a<='F')&&(b>='D'&&b<='F'));
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    bool ans = a==c;
    cout<<ans;
    ans = ans&&b[0]==d[0]&&b[1]==d[1];
    cout<<ans;
    ans = ans&&check_t(b[2],d[2]);
    cout<<ans;
    ans = ans&&abs(int(b[2]-d[2]))<=1;
    cout<<ans;
}
