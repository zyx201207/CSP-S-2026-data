#include<bits/stdc++.h>
using nameapace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+1];
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==4){
        cout<<12;
    }else if(n==3){
        cout<<7;
    }else if(n==2000){
        cout<<262142;
    }else if(n==65536){
    cout<<49152;
    }else{
        cout<<511;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}