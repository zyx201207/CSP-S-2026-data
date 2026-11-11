#include<bits/stdc++.h>
using namespace std;
#define int long long
using p=pair<int,int>;
constexpr int N=500009;
int a[N];
int pre[N];
int n,m;
bool check(int s,int x){
	if(a[s]*(x-s+1)-pre[x]+pre[s-1]<=m){
		return true;
	}
	return false;
}
int find(int x){
	int l=x,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(x,mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	return l-x+1;
}
int ans=-1e9;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,find(i));
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
