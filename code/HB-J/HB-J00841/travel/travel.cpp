#include<bits/stdc++.h>
using namespace std;
struct seat{
    string c;
    string s;
};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    seat a[3];
    int b[5];
    for(int i=0;i<4;i++){
        b[i]=0;
    }
    for(int i=0;i<2;i++){
        cin>>a[i].c>>a[i].s;
    }
    if(a[0].c==a[1].c){
        b[0]++;
    }
    if(a[0].s[0]==a[1].s[0]&&a[1].s[1]==a[0].s[1]){
        b[1]++;
    }
    if(b[0]==1&&b[1]==1&&(((a[0].s[2]=='A'||a[0].s[2]=='B'||a[0].s[2]=='C')&&(a[1].s[2]=='A'||a[1].s[2]=='B'||a[1].s[2]=='C'))||((a[0].s[2]=='D'||a[0].s[2]=='F')&&a[1].s[2]=='D'||a[1].s[2]=='F'))){
        b[2]++;
    }
    if(a[0].s[2]=='A'&&a[1].s[2]=='B'||a[0].s[2]=='B'&&a[1].s[2]=='A'||a[0].s[2]=='B'&&a[1].s[2]=='C'||a[0].s[2]=='C'&&a[1].s[2]=='B'||a[0].s[2]=='D'&&a[1].s[2]=='F'||a[0].s[2]=='F'&&a[1].s[2]=='D'){
        b[3]++;
}
    for(int i=0;i<4;i++){
        cout<<b[i];
    }
    return 0;
}
