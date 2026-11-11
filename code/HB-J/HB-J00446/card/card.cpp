#include<bits/stdc++.h>
using namespace std;
int n,m,a[500020],lst[300020],ans[300020],cnt[300020];
int t[2000020];
void update(int id,int l,int r,int x,int v){
    if (l==r){
        t[id]=v;
        return ;
    }
    int mid=(l+r)/2;
    if (x<=mid) update(id*2,l,mid,x,v);
    else update(id*2+1,mid+1,r,x,v);
    t[id]=max(t[id*2],t[id*2+1]);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for (int i=1;i<=n;i++){
        cnt[a[i]]--;
        if (cnt[a[i]]==0) ans[a[i]]+=i;
    }
    for (int i=1;i<=m;i++ ) {
        cout<<ans[i]<<" ";

    }
    cout<<"\n";
    return 0;
}