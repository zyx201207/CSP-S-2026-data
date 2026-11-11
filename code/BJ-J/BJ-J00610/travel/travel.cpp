#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(c4[2]=='F'){
        c4[2]='E';
    }
    if(c2[2]=='F'){
        c2[2]='E';
    }
    if(c1==c3){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(c1==c3 && c2[0]==c4[0] && c2[1]==c4[1]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(c1==c3 && c2[0]==c4[0] && c2[1]==c4[1] && (((c2[2]=='A' || c2[2]=='B' || c2[2]=='C')&&(c4[2]=='A' || c4[2]=='B' || c4[2]=='C')) || ((c2[2]=='D' || c2[2]=='E')&&(c4[2]=='D' || c4[2]=='E')))){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(c1==c3 && c2[0]==c4[0] && c2[1]==c4[1] && (((c2[2]=='A' || c2[2]=='B' || c2[2]=='C')&&(c4[2]=='A' || c4[2]=='B' || c4[2]=='C')) || ((c2[2]=='D' || c2[2]=='E')&&(c4[2]=='D' || c4[2]=='E')))&&abs(c2[2]-c4[2])==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
