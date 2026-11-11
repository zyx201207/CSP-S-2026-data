#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000001],tnt,ma=-1000000;
int bin_and(int a,int b){
    return (a&b);
}
void andand(int b,int times,int place){
    a[place]=0;
    if(times==m){
        ma=max(ma,b);
        return;
    }
    for(int i=n;i>=1;i--){
        if(bin_and(b,a[i])>ma){
            andand(bin_and(b,a[i]),times+1,i);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    andand(a[n],1,n);
    cout<<ma<<endl;
    return 0;
}
