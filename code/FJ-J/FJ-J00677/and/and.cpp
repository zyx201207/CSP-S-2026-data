#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NUM=2e5+5;
int a[NUM];
int n,m,ans=0;
void dfs(int b,int t,int sum){
	if(t==0){
		ans=max(ans,sum);
		return ;
	}
	for(int i=b+1;i<n;i++){
		dfs(b+1,t-1,sum&a[i]);
	}
	return ;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		dfs(0,m-1,a[i]);
	}
	cout<<ans;
	return 0;
}

