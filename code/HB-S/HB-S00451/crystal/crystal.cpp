#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,maxn;
ll a[500010],s[500010],m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;for(int i=1;i<=n;i++){cin>>a[i];}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=n;
        while(l<r){int mid=(l+r)/2;if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m)r=mid;else l=mid+1;}
        maxn=max(i-l+1,maxn);
    }
    cout<<maxn;
    return 0;
}
