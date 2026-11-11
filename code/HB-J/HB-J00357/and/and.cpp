#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m;
ll maxn;
ll a[N];
bool tmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,tmp);
    maxn=a[1];
    for(int i=1;i<=m;i++){
        maxn=maxn&a[i];
    }
    cout<<maxn;
    return 0;
}
