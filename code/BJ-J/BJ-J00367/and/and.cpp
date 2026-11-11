#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int ans,sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum=a[i]&a[i-1];
        ans=max(ans,a[i]);
    }
    if(m==n) cout<<sum;
    else if(m==1) cout<<ans;
    else cout<<0;
    return 0;
}
