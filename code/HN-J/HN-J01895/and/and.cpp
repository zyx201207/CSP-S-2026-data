#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
long long ans=LLONG_MIN;
void dfs(int x,int cnt,long long val){
//	cout<<x<<" "<<cnt<<" "<<val<<" "<<endl;
	if(x>n||cnt==m){
		if(cnt==m) ans=max(ans,val);
		return;
	}
	dfs(x+1,cnt+1,val&a[x]);
	dfs(x+1,cnt,val);
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long maxn=LLONG_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]); 
	} 
	if(m==1){
		cout<<maxn;
		return 0;
	}
	dfs(2,1,a[1]);
	dfs(2,0,-1);
	cout<<ans;
	return 0;
}

