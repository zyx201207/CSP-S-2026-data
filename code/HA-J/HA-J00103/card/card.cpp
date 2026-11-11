#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[100005];
ll d[100005];
map<ll,ll>mp;
ll vis[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
if(mp.count(a[i])){
ll id=mp[a[i]];
d[id]-=id;
d[i]+=id;
mp[a[i]]=i;
//cout<<id<<" "<<i<<"\n";
}
else mp[a[i]]=i;
}
for(int i=1;i<=n;i++){
d[i]+=d[i-1];
//cout<<d[i]<<" ";
}
for(int i=1;i<=n;i++){
d[i]+=i;
//cout<<d[i]<<" ";
vis[a[i]]=max(vis[a[i]],d[i]);
}
cout<<"\n";
for(int i=1;i<=m;i++) cout<<vis[i]<<" ";
}
