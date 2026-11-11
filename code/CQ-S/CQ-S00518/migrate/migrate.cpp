#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,x[2000005],d;
int cnt=0;
void dfs(int l,int r,int sum){
	if(l==r){
		cnt++;
		return;
	}
	if(sum==0) return;
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[l]<=d){
			dfs(i,r,sum-1);
		}
	}
	return;
}
bool check(int l,int r){
	cnt=0;
	int sum=1,l1=l;
	for(int i=l;i<=r;i++){
		if(x[i]-x[l1]>d){
			l1=i-1;
			sum++;
		}
	}
	if(sum==1) return false;
	dfs(l,r,sum);
	return cnt==2;
}
void baoli(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(check(i,j)) ans++;
		}
	}
	cout<<ans<<'\n';
	return;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	baoli();//cout<<"I don't know how to do that.\n";
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
