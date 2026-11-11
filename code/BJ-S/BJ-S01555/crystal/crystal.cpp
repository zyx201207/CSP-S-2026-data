#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; long long m;
    if(!(cin>>n>>m)) return 0;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.end());
    vector<long long> S(n+1,0);
    for(int i=1;i<=n;i++) S[i]=S[i-1]+a[i];
    int ans=1;
    for(int j=1;j<=n;j++){
        long long X=a[j];
        int lo=1, hi=j, p=j+1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            long long cnt=(long long)(j-mid+1);
            long long cost = cnt*X - (S[j]-S[mid-1]);
            if(cost<=m){ p=mid; hi=mid-1; }
            else lo=mid+1;
        }
        if(p<=j) ans=max(ans, j-p+1);
    }
    cout<<ans<<"\n";
    return 0;
}
