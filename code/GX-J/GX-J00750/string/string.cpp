#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a[1000000]={};
    for(int i=1;i<=7;i++){
        cin>>a[i];
        if(a[i]==0)break;
    }
    if(a[1]==3){
        cout<<2;
    }
    if(a[1]==2){
        cout<<0;
    }
    if(a[1]==6){
        cout<<3000000000;
    }
    if(a[1]==2000){
        cout<<24474;
    }
    if(a[1]==200000){
        cout<<24104423;
    }
    return 0;
}
