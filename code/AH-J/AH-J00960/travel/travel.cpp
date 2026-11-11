#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string che1,s1,che2,s2;
    cin>>che1>>s1>>che2>>s2;
    string pai1=s1.substr(0,2);
    string pai2=s2.substr(0,2);
    char wei1=s1[2];
    char wei2=s2[2];
    if(che1==che2){
        cout<<1;
        if(pai1==pai2){
            cout<<1;
            if(wei1<='C' && wei2<='C' || wei1>='D' && wei2>='D'){
                cout<<1;
                if(abs(wei1-wei2)==1 || wei1=='D' && wei2=='F' || wei1=='F' && wei2=='D'){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
