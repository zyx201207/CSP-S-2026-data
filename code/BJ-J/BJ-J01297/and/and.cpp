#include<bits/stdc++.h>
using namespace std;
int n,m,maxn;
int a[200005];
int forx(int st,int j,int ans){
    if(!st){
        for(int i=j+1;i<=n;i++) {
                ans=ans&a[i];
                return forx(st-1,i,ans);
        }
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        maxn=max(maxn,forx(m-1,i,a[i]));
    }
    cout<<maxn;
    return 0;
}
