#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m,a[500005],pre[500005],ans;
bool chk(int k,int p){
    return a[p]*(p-k+1)-(pre[p]-pre[k-1])<=m;
}
int bs(int l,int r,int p){
    if(l==r) return l;
    int mid=(l+r)/2;
    if(chk(mid,p)) return bs(l,mid,p);
    else return bs(mid+1,r,p);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    ans=1;
    for(int i=1;i<=n;i++){
        int st=a[i];
        int p=bs(1,i,i);
        ans=max(ans,i-p+1);
    }
    cout<<ans;
}