#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    //cout<<" "<<b[0]<<b[1]<<b[2]<<" "<<d[0]<<d[1]<<d[2];
    if(a==c){
    cout<<"1";
    }else{cout<<"0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]){
    cout<<"1";}else{
    cout<<"000";
    return 0;
    }
    if(b[2]=='A'&&d[2]=='B'){
        cout<<"11";
    }
    if(b[2]=='A'&&d[2]=='C'){
        cout<<"10";
    }
    if(b[2]=='A'&&d[2]=='D'){
        cout<<"00";
    }
    if(b[2]=='A'&&d[2]=='F'){
        cout<<"00";
    }
    if(b[2]=='B'&&d[2]=='A'){
        cout<<"11";
    }
    if(b[2]=='B'&&d[2]=='C'){
        cout<<"11";
    }
    if(b[2]=='B'&&d[2]=='D'){
        cout<<"00";
    }
    if(b[2]=='B'&&d[2]=='F'){
        cout<<"00";
    }
    if(b[2]=='C'&&d[2]=='A'){
        cout<<"10";
    }
    if(b[2]=='C'&&d[2]=='B'){
        cout<<"11";
    }
    if(b[2]=='C'&&d[2]=='D'){
        cout<<"00";
    }
    if(b[2]=='C'&&d[2]=='F'){
        cout<<"00";
    }
    if(b[2]=='D'&&d[2]=='A'){
        cout<<"00";
    }
    if(b[2]=='D'&&d[2]=='B'){
        cout<<"00";
    }
    if(b[2]=='D'&&d[2]=='C'){
        cout<<"00";
    }
    if(b[2]=='D'&&d[2]=='F'){
        cout<<"11";
    }
    if(b[2]=='F'&&d[2]=='A'){
        cout<<"00";
    }
    if(b[2]=='F'&&d[2]=='B'){
        cout<<"00";
    }
    if(b[2]=='F'&&d[2]=='C'){
        cout<<"00";
    }
    if(b[2]=='F'&&d[2]=='D'){
        cout<<"11";
    }
    return 0;
}
