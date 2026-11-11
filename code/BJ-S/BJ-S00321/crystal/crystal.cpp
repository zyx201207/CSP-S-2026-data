#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],pre[N];
signed main(){
    ios::sync_with_stdio(false);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    pre[0]=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int l=1,r=1;
    int ans=0;
    while(l<=r&&r<=n){
        while(a[r]*(r-l)-(pre[r-1]-pre[l-1])>m){
            l++;
        }
        ans=max(ans,r-l+1);
        r++;
    }
    cout<<ans<<endl;
    return 0;
}

