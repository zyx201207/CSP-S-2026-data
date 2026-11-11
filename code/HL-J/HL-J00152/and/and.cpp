#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn =2e5+10;
ll a[maxn],ans,mx=-1,k,ok=1;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       cin>>a[i];mx=max(a[i],mx);k=k&a[i];if(a[i]!=i-1)ok=0;
    }
    if(m==1){cout<<mx;return 0;}
    if(m==n){cout<<k;return 0;}
    if(ok){cout<<a[n-m+1];return 0;}
    sort(a+1,a+n+1);
    cout<<a[n-m+1]<<"\n";
    return 0;
}
