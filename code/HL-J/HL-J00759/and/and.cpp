#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300005];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);

ios::sync_with_stdio(false);
cin.tie(NULL);
ll n,m,ans=0;
cin>>n>>m;
for(ll i=1;i<=n;i++){
cin>>a[i];
}
for(ll mask=1;mask<=(1<<n);mask++){
	ll num,cnt=0;
	ll k=mask;
for(ll i=1;i<=n;i++){
	if((k&1)&&cnt==0){num=a[i];}
	if(k&1){cnt++;num=(num&a[i]);}
	k>>=1;
}
	if(cnt!=m)continue;
	ans=max(ans,num);
}
cout<<ans;
return 0;
}
