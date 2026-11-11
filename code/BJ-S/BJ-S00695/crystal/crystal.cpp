#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
const int N=5e5+7;
int a[N];

bool ok(int cnt){
    int sum=0;
    for(int i=1;i<=cnt;i++)sum+=(a[cnt]-a[i]);
    if(sum<=m)return true;
    for(int i=2;i+cnt-1<=n;i++){
        sum-=(a[i+cnt-2]-a[i-1]);
        sum+=cnt*(a[i+cnt-1]-a[i+cnt-2]);
        if(sum<=m)return true;
    }
    return false;
}

int bns(int l,int r){
    if(l==r)return l;
    int mid=(l+r+1)/2;
    if(ok(mid))return bns(mid,r);
    else return bns(l,mid-1);
}

signed main(){
    ios::sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    cout<<bns(0,n)<<endl;
    return 0;
}
