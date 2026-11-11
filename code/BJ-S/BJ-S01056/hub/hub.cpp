#include<bits/stdc++.h>
using namespace std;
int main(){
    int c,t;
    cin>>c>>t;
    if(c!=0){
        if(t==1){
            cout<<0;
        }
        else{
            for(int i=1;i<=t;i++){
                cout<<1;
            }
        }
    }
    return 0;
}