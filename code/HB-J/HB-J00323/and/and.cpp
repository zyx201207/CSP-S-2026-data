#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,a[222222];
long long maxn=0;
long long dp(long long x,long long y,long long s){
    if(y==m) return s;
    for(int i=x+1;i<=n;i++){
        return max(dp(i,y+1,s&a[i]),dp(i,y,s));
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        maxn=max(dp(i,1,a[i]),maxn);
    }
    cout<<maxn;
    return 0;
}


