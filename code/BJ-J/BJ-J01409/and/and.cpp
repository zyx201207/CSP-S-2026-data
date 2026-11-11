#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+10];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<a[n-1];
    return 0;
}
