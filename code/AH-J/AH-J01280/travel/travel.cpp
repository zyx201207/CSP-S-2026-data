#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,m;
string c1,c2;
string s1,s2;
string s[N]={"01A","01B","01C","01D","01F","02A","02B","02C","02D","02F","03A","03B","03C","03D","03F","04A","04B","04C","04D","04F","05A","05B","05C","05D","05F","06A","06B","06C","06D","06F","07A","07B","07C","07D","07F","08A","08B","08C","08D","08F","09A","09B","09C","09D","09F","10A","10B","10C","10D","10F","11A","11B","11C","11D","11F","12A","12B","12C","12D","12F","13A","13B","13C","13D","13F","14A","14B","14C","14D","14F","15A","15B","15C","15D","15F","16A","16B","16C","16D","16F","17A","17B","17C","17D","17F","18A","18B","18C","18D","18F"};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<=125;i++){
        if(s1==s[i]){
            n=i;
        }if(s2==s[i]){
            m=i;
        }
    }

    if(n/5==m/5){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if(n%5==1||n%5==2||n%5==0){
        if(m%5==2||m%5==1||m%5==0){
            cout<<"1";
            if(n%5==m%5+1||n%5==m%5-1){
                cout<<"1";
            }
        }
    }else if(n%5==3||n%5==4){
        if(m%5==3||m%5==4){
            cout<<"1";
            if(n%5==m%5+1||n%5==m%5-1){
                cout<<"1";
            }
        }
    }
    return 0;
}
