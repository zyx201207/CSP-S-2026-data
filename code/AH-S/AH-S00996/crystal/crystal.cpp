#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500055],ans=0,cnt[500055];

bool check(long long x){
	for(long long i=1;i<=n;i++){
		long long t=a[x]*(x-1)-cnt[i]+cnt[i-1];
		if(t<=m)return 1;
	}
	return 1;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cnt[i]=cnt[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	int l=0,r=0,tmp=0,ans=0;
	while(r<=n){
		tmp+=(r-l)*(a[r]-a[r-1]);
		if(tmp<=m)ans=max(ans,r-l+1),r++;
		else tmp-=(r-l)*(a[r]-a[r-1]),l++;
	}
	cout<<ans;
	return 0;
}

