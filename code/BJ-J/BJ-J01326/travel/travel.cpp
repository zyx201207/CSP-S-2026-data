#include<bits/stdc++.h>
using namespace std;
char a[4],b[4],c[4],d[4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a[0]!=c[0]||a[1]!=c[1]){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(b[0]!=d[0]||b[1]!=d[1]){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    switch(b[2]){
        case 'A':
            if(d[2]=='B') cout<<"11";
            else if(d[2]=='C') cout<<"10";
            else cout<<"00";
            break;
        case 'B':
            if(d[2]=='A'||d[2]=='C') cout<<"11";
            else cout<<"00";
            break;
        case 'C':
            if(d[2]=='B') cout<<"11";
            else if(d[2]=='A') cout<<"10";
            else cout<<"00";
            break;
        case 'D':
            if(d[2]=='F') cout<<"11";
            else cout<<"00";
            break;
        case 'F':
            if(d[2]=='D') cout<<"11";
            else cout<<"00";
            break;
    }
    return 0;
}
