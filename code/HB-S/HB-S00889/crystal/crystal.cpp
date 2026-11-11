#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,maxn=-1,ans;
    cin>>n>>m;
    long long a[500005],lost[500005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        long long k=m;ans=0;
        lost[i+1]=lost[i]+a[i+1]-a[i];
        while(k>=0&&ans<=i){
                k=k-lost[i]+lost[i-ans];
                ans++;
        }
        maxn=max(maxn,ans);
    }cout<<maxn-1;
    return 0;
}
