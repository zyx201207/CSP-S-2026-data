#include<bits/stdc++.h>
using namespace std;
int main () {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char Rche[2],Rwei[3];
    char Xche[2],Xwei[3];
    for(int i=0;i<2;i++) cin>>Rche[i];
    for(int i=0;i<3;i++) cin>>Rwei[i];
    for(int i=0;i<2;i++) cin>>Xche[i];
    for(int i=0;i<2;i++) cin>>Xwei[i];
    int s=0;
    if(Rche[0]==Xche[0]) {
        if(Rche[1]==Xche[1]) {
            s=1;
        }
    }
    if(s==0) {
        cout<<"0000";
        return 0;
    }
    cout<<s;
    s=0;
    if(Rwei[1]==Xwei[1]) {
        if(Rwei[0]==Xwei[0]) {
            s=1;
        }
    }
    if(s==0) {
        cout<<"000";
        return 0;
    }
    cout<<s;
    s=0;
    int r,x=0;
    if(Rwei[2]=='A') r=0;
    if(Rwei[2]=='B') r=0;
    if(Rwei[2]=='C') r=0;
    if(Rwei[2]=='F') r=1;
    if(Rwei[2]=='D') r=1;
    if(Xwei[2]=='A') x=0;
    if(Xwei[2]=='B') x=0;
    if(Xwei[2]=='C') x=0;
    if(Xwei[2]=='F') x=1;
    if(Xwei[2]=='D') x=1;
    if(r==x) {
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(Rwei[0]==Xwei[0]+1) {
    cout<<"1";
    return 0;
    }
    if(Rwei[0]==Xwei[0]-1) {
        cout<<"1";
        return 0;
    }
    if(Rwei[0]==Xwei[0]){
		cout<<"1";
		return 0;
		}
        cout<<"0";
    return 0;
}
