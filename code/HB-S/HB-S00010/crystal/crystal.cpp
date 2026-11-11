#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
const int N=5e5+5;
using namespace std;
int n,m;
ll a[N],p[N];
bool check(int x){
    for(int i=x;i<=n;i++)
        if(a[i]*x-p[i]+p[i-x]<=m)return true;
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
    int l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }cout<<l-1;
    return 0;
}
