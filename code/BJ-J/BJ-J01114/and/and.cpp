#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m;
ll ans;
struct node{
    int t;
    ll x;
}a[N];
bool cmp(node a,node b){
    if(a.t==b.t) return a.x>b.x;
    return a.t>b.t;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].t=__builtin_popcountll(a[i].x);
    }
    sort(a+1,a+1+n,cmp);
    ans=a[1].x;
    for(int i=1;i<=m;i++){
        ans=ans&a[i].x;
       //cout<<a[i].x<<' ';
    }
    //cout<<'\n';
    cout<<ans;
   return 0;
}
