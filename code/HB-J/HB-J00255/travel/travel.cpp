#include<iostream>
#include<cstdio>
using namespace std;
int an,bn,apai,bpai;
char alie,blie;
string am,bm;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>an>>am>>bn>>bm;
    apai=(am[0]-'0')*10+(am[1]-'0');
    bpai=(bm[0]-'0')*10+(bm[1]-'0');
    alie=am[2];
    blie=bm[2];
    bool f1=(an==bn);
    bool f2=(apai==bpai);
    int zy[10]={1,1,1,2,0,2,0,0,0,0};
    cout<<f1;
    cout<<(f1&&f2);
    cout<<(f1&&f2&&(zy[(int)alie-'A']==zy[(int)blie-'A']));
    if( (alie=='A'&&blie=='B'
       ||alie=='B'&&blie=='A'
       ||alie=='B'&&blie=='C'
       ||alie=='C'&&blie=='B'
       ||alie=='F'&&blie=='D'
       ||alie=='D'&&blie=='F')
       &&f1&&f2
       )
        cout<<1;
    else cout<<0;
    return 0;
}
