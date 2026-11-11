#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cx>>sx>>cy>>sy;
    if(cx==cy){
        cout<<'1';
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(sx[0]==sy[0]&&sx[1]==sy[1]){
        cout<<'1';
    }
    else{
        cout<<"000";
        return 0;
    }
    int p=1;
    sx[3]=sx[2];
    sy[3]=sy[2];
    char a=max(sx[3],sy[3]),b=min(sx[3],sy[3]);
    if((sx[3]=='D'&&sy[3]=='F')||(sx[3]=='F'&&sy[3]=='D')||(sx[3]=='A'&&sy[3]=='B')||(sx[3]=='A'&&sy[3]=='C')||(sx[3]=='B'&&sy[3]=='A')||(sx[3]=='C'&&sy[3]=='A')||(sx[3]=='B'&&sy[3]=='C')||(sx[3]=='C'&&sy[3]=='B'));{
        if((sx[3]=='D'&&sy[3]=='C')||(sx[3]=='C'&&sy[3]=='D')){
            cout<<"00";
            return 0;
        }
        if(a-b>1&&b!='D'&&(!(a=='C'&&b=='A'))){
            cout<<"00";
            return 0;
        }
        cout<<'1';
        p=0;
    }
    if(p){
        cout<<"00";
        return 0;
    }
    if((a-b==1)||(a=='F'&&b=='D')){
        if(a=='D'){
            cout<<'0';
            return 0;
        }
        cout<<'1';
        return 0;
    }
    cout<<'0';
    return 0;
}
