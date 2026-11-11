#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans;
int a[N],d[N],pre[N];
int query(int l,int r){return pre[r]-pre[l-1];}
int check(int l,int r){return (r-l)*a[r]-query(l,r-1);}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
        if(i<n)d[i]=a[i+1]-a[i];
    }
    int l=1,r=1;
    while(r<=n&&l<=n){
        while(r<=n&&check(l,r)<=m)r++;
        l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
