#include<bits/stdc++.h>
#define z long long
using namespace std;z a[500000],n,m,y=1,l=0,r=0,h=0;int main(){freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);cin>>n>>m;for(z i=0;i<n;i++)cin>>a[i];sort(a,a+n);while(r<n){while(h>m)h-=a[r]-a[l++];y=max(y,(++r)-l);h+=(a[r]-a[r-1])*(r-l);}cout<<y;return 0;}
