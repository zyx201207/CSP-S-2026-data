#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200005;
int n,m;
int a[N];
int dp[N];
int ans=0;
void dfs(int x,int cnt,int num){
	if(cnt>x) return;
	if(x>n) return;
	if(cnt==m){
		ans=max(ans,num);
		return;
	}
	dfs(x+1,cnt+1,(cnt==0?a[x]:(num&a[x])));
	dfs(x+1,cnt,num);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((1LL<<((int)log2(a[i])+1LL))-1LL!=a[i]) f=0;
	}
	if(f){
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<"\n";
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n]<<"\n";
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++) sum=(sum&a[i]);
		cout<<sum<<"\n";
		return 0;
	}
	if(m==2){
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum<<"\n";
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<"\n";
	return 0;
}
