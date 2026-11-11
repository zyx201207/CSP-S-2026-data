#include<bits/stdc++.h>
using namespace std;
string cr,zr,cx,zx;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cr>>zr>>cx>>zx;
    if(cr==cx) cout<<1;
    else {
        cout<<"0000";
        return 0;
    }
    int a=zr[0]*10+zr[1],b=zx[0]*10+zx[1];
    if(a==b) cout<<1;
    else {
        cout<<"000";
        return 0;
    }
    char c=zr[2],d=zx[2];
    if(c=='A'&&(d=='B'||d=='C')||c=='B'&&(d=='A'||d=='C')||c=='C'&&(d=='B'||d=='A')||c=='D'&&d=='F'||c=='F'&&d=='D') cout<<1;
    else {
            cout<<"00";
            return 0;
    }
    if(c=='A'&&d=='B'||c=='B'&&d=='A'||c=='B'&&d=='C'||c=='C'&&d=='B'||c=='F'&&d=='D'||c=='D'&&d=='F') cout<<1;
    else cout<<0;
   return 0;
}
