#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],cnt[N],sum,ans;
bool st[N];
void dfs(long long sum,long long cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==1) continue;
		st[i]=1;
		dfs(sum&a[i],cnt+1);
		st[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		long long maxv=-9e18;
		for(int i=1;i<=n;i++) maxv=max(maxv,a[i]);
		cout<<maxv;
		return 0;
	}
	if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++) sum&=a[i];
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum=a[i];
		st[i]=1;
		dfs(sum,1);
		st[i]=0;
	}
	cout<<ans;
	return 0;
}
