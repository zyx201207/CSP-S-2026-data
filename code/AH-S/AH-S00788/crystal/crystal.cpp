#include<bits/stdc++.h>
using namespace std;

long long n,m,ans=0;
long long k[511111],qzh[511111];

long long handle(int x){
    long long l=1,r=x;
    while(l<=r){
        long long mid=(l+r)>>1;
        long long ttt=(x-mid+1)*k[x]-(qzh[x]-qzh[mid-1]);
        if(ttt<=m){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return x-l+1;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int a=1;a<=n;a++){
        cin>>k[a];
    }
    sort(k+1,k+n+1);
    for(int a=1;a<=n;a++){
        qzh[a]=qzh[a-1]+k[a];
    }
    for(int a=1;a<=n;a++){
        ans=max(ans,handle(a));
    }
    cout<<ans;
    return 0;
}
