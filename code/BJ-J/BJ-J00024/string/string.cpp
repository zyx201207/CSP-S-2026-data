#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
char c[200005];
int a[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int r=n,ans=0;
    for(int l=1;l<=n;l++){
        int sum=0;
        while(l<r&&sum+a[r]<=a[l]){
            ans+=a[r]*(c[r]!=c[l]);
            sum+=a[r];
            r--;
        }
        if(l>=r) break;
        if(sum!=a[l]){
            a[r]-=a[l]-sum;
            ans+=(a[l]-sum)*(c[r]!=c[l]);
        }
    }
    cout<<ans;
}
