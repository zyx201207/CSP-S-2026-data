#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1;
long long a[200050];
void dfs(int t,long long sum,int w){
	if(t==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=w+1;i<=n-m+t+1;i++){
		if(t==0) dfs(t+1,a[i],i);
		else dfs(t+1,sum&a[i],i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		exit(0);
	}else if(m==2){
		for(int i=1;i<n;i++){
			if(a[i]<=ans) continue;
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		exit(0);
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		exit(0);
	}else if(n>=2000){
		sort(a+1,a+n+1);
		cout<<a[m];
		exit(0);
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
