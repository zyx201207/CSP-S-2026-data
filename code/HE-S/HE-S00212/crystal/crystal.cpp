#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int MAXN=5e5+800;
long long ask[MAXN];
bool check(int len){
	long long p=0;
	for(int i=1;i<=len;++i)
		p=p+(ask[len]-ask[i]);
	if(p<=m) return 1;
	for(int i=2;i<=n-len+1;++i){
		p=p-(ask[i+len-2]-ask[i-1])+(len-1ll)*1ll*(ask[i+len-1]-ask[i+len-2]);
		if(p<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>ask[i];
	sort(ask+1,ask+n+1);
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){ans=mid;l=mid+1;}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
