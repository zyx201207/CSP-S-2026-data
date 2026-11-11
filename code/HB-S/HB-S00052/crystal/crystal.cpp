#include<bits/stdc++.h>
using namespace std;
long long a[500005],pre[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,ans=1,l=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n&&l<=i;i++){
        while(a[i]*(i-l-1)-pre[i-1]+pre[l]>m&&l<=n) l++;
        ans=max(ans,i-l);
    }
    cout<<ans;
    return 0;
}
