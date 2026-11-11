#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long aaa(long long x,int ii,int f){
    if(f==m) return x;
    long long anss=-1;
    for(int i=ii;i<=n-(m-f)+1;i++){
        anss=max(anss,x&aaa(a[ii],ii+1,f+1));
    }
    return anss;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=-1;
    for(int i=1;i<=n-m+1;i++){
        ans=max(ans,aaa(a[i],i+1,1));
    }
    cout<<ans;
    return 0;
}
