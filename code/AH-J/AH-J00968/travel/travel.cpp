#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int as=0;
    as+=(a[1]-'0');
    as*=10;
    as+=(a[0]-'0');
    int bs=0;
    bs+=(c[1]-'0');
    bs*=10;
    bs+=(c[0]-'0');
    int ass=0;
    ass+=(b[1]-'0');
    ass*=10;
    ass+=(b[0]-'0');
    int bss=0;
    bss+=(d[1]-'0');
    bss*=10;
    bss+=(d[0]-'0');
    char asss=b[2];
    char bsss=d[2];
    if(as==bs){
        if(ass==bss){
            if(asss!='D'&&asss!='f'&&bsss!='D'&&bsss!='f'||asss!='A'&&asss!='B'&&asss!='C'&&bsss!='A'&&bsss!='B'&&bsss!='C'){
                if(asss=='A'&&bsss=='B'||asss=='B'&&bsss=='A'||asss=='B'&&bsss=='C'||asss=='C'&&bsss=='B'||asss=='D'&&bsss=='F'||asss=='F'&&bsss=='D'){
                    cout<<"1111";
                }else cout<<"1110";
            }else cout<<"1100";
        }else cout<<"1000";
    }else cout<<"0000";
    return 0;
}
