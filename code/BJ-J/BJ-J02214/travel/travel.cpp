#include<bits/stdc++.h>
using namespace std;
struct node{
    int part;
    string seatt;
    int seatn;
    char seata;
};
node r,x;
int main(){
    //:
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //
    cin>>r.part>>r.seatt>>x.part>>x.seatt;
    r.seatn=r.seatt[0]*10+r.seatt[1];
    x.seatn=x.seatt[0]*10+x.seatt[1];
    r.seata=r.seatt[2];
    x.seata=x.seatt[2];
    if(r.part==x.part){
        cout<<1;
    }else{
        cout<<0;
    }
    if(r.seatn==x.seatn&&r.part==x.part){
        cout<<1;
    }else{
        cout<<0;
    }
    if(r.seatn==x.seatn&&r.part==x.part&&((r.seata>='A'&&r.seata<='C'&&x.seata>='A'&&x.seata<='C')||(r.seata>='D'&&r.seata<='E'&&x.seata>='D'&&x.seata<='E'))){
        cout<<1;
    }else{
        cout<<0;
    }
    int t=r.seata-x.seata;
    if(r.seatn==x.seatn&&r.part==x.part&&((r.seata>='A'&&r.seata<='C'&&x.seata>='A'&&x.seata<='C')||(r.seata>='D'&&r.seata<='E'&&x.seata>='D'&&x.seata<='E'))&&(t==1||t==-1)){
        cout<<1;
    }else{
        cout<<0;
    }
return 0;
}