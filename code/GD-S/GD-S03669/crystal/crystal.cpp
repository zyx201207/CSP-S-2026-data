#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
ll n,m,a[10000005],b[10000005],ent=0,ans=0,cnt;
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ll dm=m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(ll i=1;i<=n;i++){
		ans=max(ans,ent);
		dm=m;
		ent=0;
		for(ll j=1,k=1;j<=n;j++,k++){
			cnt=max(a[j],a[i])-min(a[j],a[i]);
			if(cnt==0) k--;
			if(a[j+1]-a[j]==0) k--; 
			if(k<=-1) k=0;
			if(dm-cnt*k>=0){
			ent++;
			dm-=cnt*k;
			}
	} 
}
	cout<<ans;
	return 0;
} 
