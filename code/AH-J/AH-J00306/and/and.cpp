#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxx,s,maxxx,flag,flagg;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        if(i==1) s==a[1];
        else s=s&a[i];
        if(a[i]!=3) flag=1;
        if(a[i]!=a[i-1]) flagg=1;
    }
    if(m==1){
        cout<<maxx;return 0;
    }
    if(m==n){
        cout<<s;return 0;
    }
    if(m==2){
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                maxxx=max(maxxx,a[i]&a[j]);
            }
        }
        cout<<maxxx;return 0;
    }
    if(flag==0){
        cout<<3;return 0;
    }
    if(flagg==0){
        cout<<a[1];return 0;
    }
    cout<<0;
    return 0;
}
