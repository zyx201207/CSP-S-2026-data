#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200005],ans,ans2;
void dfs(int i,int s,int sum){
	if(s==m){
		ans=max(ans,sum);
		return;
	}
	if(i>n||sum<=ans) return;
	if(s+n-i>=m) dfs(i+1,s,sum);
	dfs(i+1,s+1,sum&a[i]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<a[n];
		return 0;
	}
	for(int i=1;i<=n-m+1;i++)
		dfs(i+1,1,a[i]);
	cout<<ans;
	return 0;
} 
