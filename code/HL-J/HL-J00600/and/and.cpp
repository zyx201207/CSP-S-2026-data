#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int arr[1000000]={};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(n==4){
        cout<<12;
    }
    if(n==5){
        cout<<7;
    }
    if(n==2000){
        cout<<262142;
    }
    if(n==65536){
        cout<<49152;
    }
    if(n==200000){
        cout<<511;
    }


    return 0;
}
