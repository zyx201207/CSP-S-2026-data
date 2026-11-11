#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int q,w,e,r;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    q=int((a[0]-'0'))*10+int((a[1]-'0'));
    w=int((b[0]-'0'))*10+int((b[1]-'0'));
    e=int((c[0]-'0'))*10+int((c[1]-'0'));
    r=int((d[0]-'0'))*10+int((d[1]-'0'));
    if(q==e){
        cout<<1;
    }else{
        cout<<0;
    }
    if(w==r&&q==e){
        cout<<1;
    }else{
        cout<<0;
    }
    if(w==r&&q==e&&(('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')||(b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F'))){
        cout<<1;
    }else{
        cout<<0;
    }
    if(w==r&&q==e&&((b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F')||(d[2]=='A'&&b[2]=='B')||(d[2]=='B'&&b[2]=='A')||(d[2]=='B'&&b[2]=='C')||(d[2]=='C'&&b[2]=='B'))){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
