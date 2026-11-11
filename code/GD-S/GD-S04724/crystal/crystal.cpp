#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	long long m;
	cin>>n>>m;
	vector<long long> a(n+1),c(n),s(n);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
		s[i]=a[i+1]-a[1];
	}
	int ans=1,p=0;
	long long sum=0;
	for(int i=1;i<n;i++){
		for(;p<i && sum+c[i]*(i-p)>m;p++) sum-=s[i-1]-s[p];
		sum+=c[i]*(i-p);
		if(sum<=m) ans=max(ans,i-p+1);
		//cout<<ans<<" "<<p<<" "<<sum<<'\n';
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
} 
