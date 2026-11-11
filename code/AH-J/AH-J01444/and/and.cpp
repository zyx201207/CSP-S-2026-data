#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a[6666666],n,m,maxn,cnt=0;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
    cin>>a[i];
    maxn=max(maxn,a[i]);
    }
    cnt=maxn;
    sort(a,a+n);
    for(long long i=0;i<n-m-1;i--){
    cnt=a[i];
    }
    cout<<cnt;
    return 0;
    }
    
    
    
    
