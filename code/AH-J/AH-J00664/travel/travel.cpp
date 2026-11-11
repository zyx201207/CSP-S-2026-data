#include<bits/stdc++.h>
#define int long long
using namespace std;
string w,x,y,z;
bool flag;
signed main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>w>>x>>y>>z;
string m=x.substr(0,2);
string n=z.substr(0,2);
char a=x[2],b=z[2];
if(w==y) cout<<1;
else cout<<0;
if(w==y&&m==n)cout<<1;
else cout<<0;
if(w==y&&m==n){
    if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')){
        cout<<1;
        flag=1;
    }else if((a=='D'||a=='F')&&(b=='D'||b=='F')){
        cout<<1;
        flag=1;
    }else{
        cout<<0;
    }
}else{
    cout<<0;
}
if(w==y&&m==n&&flag){
    int sx=a-'0',sy=b-'0';
    int s=abs(sx-sy);
    if(s==1||((a=='D'&&b=='F')||(a=='F'&&b=='D'))) cout<<1;
    else cout<<0;
}else{
    cout<<0;
}
return 0;
}
