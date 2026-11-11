#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
            int s=a[i],j;
            int sum=0;
            for(j=0;sum<m;j++) sum+=(a[i]-a[j])>=0?(a[i]-a[j]):(a[j]-a[i]);
            ans=max(ans,j);
    }
    cout<<ans;
    return 0;
}
