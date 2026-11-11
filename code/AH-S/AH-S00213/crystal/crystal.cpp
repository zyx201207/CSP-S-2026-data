#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s[500005],diff[500005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,s+n+1);
    for(int i=1;i<=n;i++){
        diff[i]=s[i]-s[i-1];
    }
    int l=1,r=1,maxn=0,sum=0;
    while(l<=r){
        while(r<=n&&sum<=m){
            r++;sum+=(r-l)*diff[r];
        }
        maxn=max(maxn,r-l);
        sum-=s[r]-s[l];
        l++;
    }
    cout<<maxn;
    return 0;
}
