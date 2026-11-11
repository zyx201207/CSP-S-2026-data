#include<bits/stdc++.h>
using namespace std;
int a,b;
string s,t;
char x,y;
bool f(char a,char b){
    return x==a&&y==b||x==b&&y==a;
}
void solve(){
    cin>>a>>s>>b>>t;
    if(a==b) cout<<1;
    else{
        cout<<"0000\n";
        return;
    }
    if(s[0]+s[1]==t[0]+t[1]) cout<<1;
    else{
        cout<<"000\n";
        return;
    }
    x=s[2],y=t[2];
    if(f('A','B')||f('A','C')||f('B','C')||f('D','F')) cout<<1;
    else{
        cout<<"00\n";
        return;
    }
    if(f('A','B')||f('B','C')||f('D','F')) cout<<1<<"\n";
    else{
        cout<<0;
        return;
    }
}
int main(){
    ios::sync_with_stdio(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
