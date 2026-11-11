#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[200005];
void dfs(int step,int sum,int cnt){
	if(step>n){
		if(cnt==m) ans=max(ans,sum);
		return ;
	}
	dfs(step+1,sum&a[step],cnt+1);
	dfs(step+1,sum,cnt);
}
void solve1(){
	ans=0;
	for(int i=1;i<=n;i++){
		dfs(i+1,a[i],1);
	}
	cout<<ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		solve1();
	}
	else if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}
	else if(m==2){
		int sum;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum=a[i]&a[j];
				ans=max(sum,ans);
			}
		}
		cout<<ans;
	}
	return 0;
}

