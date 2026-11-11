#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=500005;

int n,m;
int a[N],frs[N];

bool check(int k){
	for(int i=k;i<=n;i++){
		if(a[i]*(k-1)-(frs[i-1]-frs[i-k])<=m) return true;
	}
	return false;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++) frs[i]=frs[i-1]+a[i];
	
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	
	cout<<ans;
	
	return 0;
}
