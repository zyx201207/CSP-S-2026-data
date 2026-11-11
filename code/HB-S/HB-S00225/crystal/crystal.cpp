#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ans=1,pre[N];
bool check(int mid){
    for(int i=1;i+mid-1<=n;i++){
        int j=i+mid-1;
        int sum=pre[j]-pre[i-1];
        if(mid*a[j]-sum<=m){
            return 1;
        }
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int l=1,r=n+1;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    cout<<l-1<<'\n';
    return 0;
}
