#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int tree[N*4];
int a[N];
int n,m;
void build(int root,int s,int e){
    if(s==e){
        tree[root]=a[s];
        return;
    }int mid=(s+e)/2;
    build(root*2,s,mid);
    build(root*2+1,mid+1,e);
    tree[root]=(tree[root*2]&tree[root*2+1]);
}

int query(int root,int s,int e,int l,int r){
    int sum=(1<<31)-1;
    if(l<=s&&r>=e){
        return tree[root];
    }
    int mid=(s+e)/2;
    if(l<=mid){
        sum=(sum&query(root*2,s,mid,l,r));
    }if(r>mid){
        sum=(sum&query(root*2+1,mid+1,e,l,r));
    }return sum;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    build(1,1,n);
    int maxn=-1;
    for(int i=1;i+m-1<=n;i++){
        maxn=max(maxn,query(1,1,n,i,i+m-1));
    }cout<<maxn;
    return 0;
}
