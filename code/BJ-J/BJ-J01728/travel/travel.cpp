#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int a,b;
char p[3],q[3];

bool check(char x,char y){
    if((x=='A'&&y=='B')||(x=='B'&&y=='C')||(x=='B'&&y=='A')||(x=='D'&&y=='E')||(x=='E'&&y=='D')){
        return 1;
    }else return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a;
    for(int i=0;i<3;i++){
        cin>>p[i];
    }
    cin>>b;
    for(int i=0;i<3;i++){
        cin>>q[i];
    }
    if(a==b) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }

    for(int i=0;i<=1;i++){
        if(p[i]!=q[i]){
            cout<<"000";
            return 0;
        }
    }
    cout<<"1";

    if((p[2]!='E'&&p[2]!='D'&&q[2]!='D'&&q[2]!='E')||(p[2]=='D'&&q[2]=='E')||(p[2]=='E'&&q[2]=='D')){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }

    if(check(p[2],q[2])){
        cout<<"1";
    }else{
        cout<<"0";
        return 0;
    }


}
