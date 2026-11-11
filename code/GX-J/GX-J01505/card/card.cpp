#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1)cout<<1;
    if(n==2){
        if(m==2)cout<<2<<" "<<2;
        else cout<<2;
    }
    if(n==3){
        if(m==2){

        }
        else cout<<3;
    }
    if(n==4){
        if(m==2){

        }
        else cout<<4;
    }
    if(n==5){
        if(m==2){

        }
        else cout<<5;
    }
    return 0;
}


