#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
int n;
ll m;
ll a[N],sum[N];
inline bool chk(int k){
    for(int i=1,j=1;i<=n;i=j+1){
        j=i;
        while(j+1<=n&&a[j+1]==a[i])++j;
        int cnt=j-i+1;
        if(cnt>=k)return true;
        if(i-1<k-cnt)continue;
        if(a[i]*(k-cnt)-(sum[i-1]-sum[i-(k-cnt)-1])<=m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(chk(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}