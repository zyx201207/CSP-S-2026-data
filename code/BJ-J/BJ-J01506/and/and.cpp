#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int n,m,maxn,ans,a[1e6];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdiout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0:i<n-m;i++){
        for(int j=i;j<i+m;j++){
            if(j==i) ans=a[m];
            else ans&=a[m];
        }
        maxn=max(maxn,ans);
        ans=0;
    }
    cout<<maxn;
    return 0;
}