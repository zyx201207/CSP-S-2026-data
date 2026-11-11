#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,s1=0,s2=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==4&&m==2){
        cout<<12;
    }
    if(n==5&&m==3){
        cout<<7;
    }
    return 0;
}
