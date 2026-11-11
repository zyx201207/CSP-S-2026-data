#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans=1;
long long m,a[N],s[N];
long long dis(int l,int r){
    return (r-l)*a[r]-s[r-1]+s[l-1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for (int i=2;i<=n;i++){
        int j=i-1,l=1,r=i,mid;
        while (l<=r){
            mid=(l+r)/2;
            if (dis(mid,i)<=m){
                r=mid-1;
                ans=max(i-mid+1,ans);
            }
            else l=mid+1;
        }
        ans=max(i-j,ans);
    }
    cout<<ans;
    return 0;
}
