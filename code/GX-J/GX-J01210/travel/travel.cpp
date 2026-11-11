#include<bits/stdc++.h>
using namespace std;
int ia,ib;
char ca[5],cb[5];
int main(){
    cin>>ia;
    for(int i=1;i<=3;i++){
        cin>>ca[i];
    }
    cin>>ib;
    for(int i=1;i<=3;i++){
        cin>>cb[i];
    }
    if(ia==ib) cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    long long cia1=(ca[1]-'0')*10+ca[2]-'0',cib1=(cb[1]-'0')*10+cb[2]-'0';
    if(cia1==cib1) cout<<1;
    else{
        cout<<0<<0<<0;
        return 0;
    }
    long long cia2=ca[3]-'A',cib2=cb[3]-'A';
    if(cia2<=2&&cib2<=2){
        cout<<1;
        if(cia2==cib2+1||cia2==cib2-1) cout<<1;
        else cout<<0;
    }
    else if(cia2>2&&cib2>2){
        cout<<1;
        if(cia2==cib2+1||cia2==cib2-1) cout<<1;
        else cout<<0;
    }
    else cout<<0<<0;
    return 0;
}
