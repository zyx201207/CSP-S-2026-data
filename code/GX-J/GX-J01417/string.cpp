#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string a;
    cin>>n;
    int k[15]={};
    for(int j=0;j<=n;j++){
        n[j]=n%10;
        n=n/10;
    }
    for(int j=0;j<15;j++){
        a=k[j];
    }
    if(n=k){
        cout<<0;
    }
    return 0;
}
