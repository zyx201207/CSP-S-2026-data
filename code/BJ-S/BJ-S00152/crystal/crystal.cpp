#include <bits/stdc++.h>
using namespace std;

int main(){
    long int n;
    long int m;
    long int a[5000001];
    long int d[5000001];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];}
    long int min_d;
    for(int i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];}
    if(m<min_d){
        cout<<0<<endl;
    }
    else if(m==min_d){
        cout<<2<<endl;
    }


    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    return 0;
}
