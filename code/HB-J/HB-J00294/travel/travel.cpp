#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int e=0,f=0,g=0,h=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        e=1;
    }
    if(b[0]==d[0]&&b[1]==d[1]&&e==1){
        f=1;
    }
    if((b[2]=='A'&&(d[2]=='B'||d[2]=='C')) || (b[2]=='B'&&(d[2]=='A'||d[2]=='C')) || (b[2]=='C'&&(d[2]=='A'||d[2]=='B'))){
        if(f==1){
            g=1;
        }
    }
    if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
        if(g==1){
            h=1;
        }
    }
    cout<<e<<f<<g<<h;
    return 0;
}
//RP++
//CCF help me work out the second text
//Maoxiaojiou help me RP++
//Maobailing help me RP++
