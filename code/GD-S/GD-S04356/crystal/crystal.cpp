#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int maxn=500005;

ll n,m;
ll c[maxn];
ll dp[maxn];
ll ans[maxn];
ll maxn2;

int main(){
	ios::sync_with_stdio(false);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	ll a[n+5];
	ll end=-1;
	
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		ans[a[i]]++;
		maxn2=max(maxn2,a[i]);
	}
	a[0]=a[1];
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++) {
		c[i-1]=a[i]-a[i-1];//c[i-1]Îªi-1ÓëiµÄ²î
		//cout<<c[i-1]<<" ";
	}

	for(int i=1;i<=maxn2;i++) {
		end=max(end,ans[i]);
		//cout<<ans[i]<<" ";
	}
	
	for(int i=1;i<=m;i++) {
		dp[i]=end;
	}
	
	//cout<<end<<" ";

	if(m==0) {
		cout<<end-1<<endl;
		return 0;
	}
	ll fu=c[n];
	ll num=1;
	ll j=m;
	ll qu=0;
	for(int i=1;i<=n;i++){
		if(fu>m) break;
		if(fu==0) {
			num=1;
			fu+=c[n-i];
			if(c[n-i]!=0) qu=c[n-i];
			continue; 
		}
		dp[j]=max(dp[j],dp[j-fu]+1);
		if(c[n-i]==0) fu+=qu;
		else fu+=c[n-i]+fu*num;
		num++;
		//cout<<endl;
	} 
	cout<<dp[m]+1<<endl;
	
	return 0;
}
