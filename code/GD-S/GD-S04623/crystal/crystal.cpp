#include<bits/stdc++.h>
using str;
main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int m;
    int n;
    int d;
    cin >> n >> m ;
    string c [n];
    for(int i=0; i<n ;i++){
        cin >> c[i];
        if(c[i]<c[i-1]){
            d=c[i-1];
            c[i-i]=c[i];
            c[i]=d;
        }

    }
    int sum=m;
    int sum1=0;
    int sum2=0;
    for(int i=0; i<n ;i++){
        if(c[i]+sum>c[i+1]){
            sum1=sum1+1;
            sum=sum+c[i]-c[i+1];
        }else if(sum1>sum2){
            sum2=sum1;
        }else if(c[i]+sum<c[i+1]){

        }

    }
    return 0;
}
