#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e5+10;

int n,m,a[N],s[N];
int find(int i){
    int l=0,r=i-1,mid;
    while(l<=r){
        mid=l+r>>1;
        if(mid*a[i]-s[mid]<=m+s[i]-i*a[i])r=mid-1;
        else l=mid+1;
    }
    return i-r-1;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int mi=1e18;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mi=min(mi,a[i]);
    }
    for(int i=1;i<=n;i++){
        a[i]-=mi;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int j=0,ans=1;
    for(int i=1;i<=n;i++){
        while(j<i&&s[j]-j*a[i]>m+s[i]-i*a[i])j++;
        ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}
