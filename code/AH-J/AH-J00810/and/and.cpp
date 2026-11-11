#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=min(20000,n-m+1);i++){
        int sum=a[n-i+1];
        for(int j=n-i;j>=max(1,n-m-i+2);j--) sum=sum&a[j];
        ans=max(sum,ans);
    }
    cout<<ans;
    return 0;
}
