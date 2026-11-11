//CSP-J succeed

#include <bits/stdc++.h>
using namespace std;
#define llong long long

auto fr=[]()->void{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	return;
};

const int N=2e5+10;
int a[N];
int n,m;
int best,ans;
void dfs(int i,int k)
{
	if(i>n){
		if(k==m+1){
			best=max(best,ans);
		}
		return;
	}else if(k+n-i+1<m){
		return;
	}
	if(k==m+1){
		best=max(best,ans);
		return;
	}
	
	if(k==0){
		ans=a[i];
		dfs(i+1,k+1);
		ans=0;
		dfs(i+1,k);
	}else{
	int x=ans;
	ans=ans&a[i];
	dfs(i+1,k+1);
	ans=x;
	dfs(i+1,k);
}
	
	return;
}
signed main()
{
	fr();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	dfs(1,0);
	
	cout<<best;
	
	return 0;
}
