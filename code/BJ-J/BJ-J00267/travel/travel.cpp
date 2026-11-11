#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2;
    string b1,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1!=a2){
        cout<<"0000";
    }else{
        if(b1[0]!=b2[0] || b1[1]!=b2[1]){
            cout<<"1000";
        }else{
            if((b1[2]<='C' && b2[2]<='C') || (b1[2]>'C' && b2[2]>'C')){
                if(abs(int(b1[2]-b2[2]))==1){
                    cout<<"1111";
                }else{
                    cout<<"1110";
                }
            }else{
                cout<<"1100";
            }
        }
    }
    return 0;
}
