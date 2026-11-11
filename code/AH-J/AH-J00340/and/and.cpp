#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll a[200010],maxn,m,n,mm;
void dfs(int cur,ll ans,int cnt){
	if(cnt==m) maxn=max(maxn,ans);
	if(cur>n){
		return ;
	}
	dfs(cur+1,ans&a[cur],cnt+1);
	dfs(cur+1,ans,cnt);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=20){
		for(int i=1; i<=n; i++){
			dfs(i+1,a[i],1);
		}
		cout<<maxn;
		return 0;
	}
	if(m==1){
		cout<<a[n];
	}
	else if(m==n){
		ll ans=a[1];
		for(int i=2; i<=n; i++){
			ans=ans^a[i];
		}
		cout<<ans;
	}
	else if(m==2){
		ll tot=-1;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				tot=max(tot,a[i]&a[j]);
			}
		}
		cout<<tot;
	}
	else {
		cout<<a[n-m+1];
	}
	return 0;
}