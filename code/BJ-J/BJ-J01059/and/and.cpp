#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long

int n,m;
int a[N];
struct node {
    int fa,l,r,id,z;
} tr[N];

int build(int fa,int l,int r,int id){
    if (l==r){
        tr[id]={fa,l,r,id,a[l]};
        return tr[id].z;
    }
    tr[id]={fa,l,r,id,build(id,l,(l+r)/2,id*2) & build(id,(l+r)/2+1,r,id*2+1)};
    return tr[id].z;
}
int he(int id,int l,int r){
    if (l<=tr[id].l && tr[id].r<=r) return tr[id].z;
    if (tr[id].r<l || r<tr[id].l) return -1;
    int ans=-1;
    int x;
    x=he(id*2,l,(l+r)/2);if (x!=-1)ans=(ans==-1?x:ans&x);
    x=he(id*2+1,(l+r)/2+1,r);if (x!=-1)ans=(ans==-1?x:ans&x);
    return ans;
}

signed main(){
    freopen("and3.in","r",stdin);
    freopen("and3.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    build(1,1,n,1);
    int ans=0;
    for (int i=1;i+m<=n;i++){
        ans=max(ans,he(1,i,i+m));
    }
    cout<<ans;
}
