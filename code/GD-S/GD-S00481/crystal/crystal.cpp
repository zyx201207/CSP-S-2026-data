#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,ans=0;
ll m,s[510007],a[510007];

bool chk(int len){
	for(int i=1;i+len-1<=n;++i){
		ll sum=a[i+len-1]-a[i-1];
		ll tmp=s[i+len-1]*len;
		if(m>=tmp-sum)return true;
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;++i){
		a[i]=a[i-1]+s[i];
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(chk(mid)){
			ans=max(mid,ans);
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
} 
