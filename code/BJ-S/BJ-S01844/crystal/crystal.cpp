#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+9;
ll n,m,a[N],b[N];
bool ch(int x){
    ll cnt=0;
    for(int i=1;i<x;i++)cnt+=b[n-i+1]*(x-i);
    for(int i=n;i>=x-1;i--){
        if(cnt<=m)return 1;
        cnt+=-b[i]*(x-1)+a[i-1]-a[i-x];
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)b[i]=a[i]-a[i-1];
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(ch(mid)==1)l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}