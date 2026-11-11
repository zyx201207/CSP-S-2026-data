#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m,ans;
long long a[MAXN];
void dfs(int o){
	if(o>=m){
		long long nans=1;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1])nans++;
		}
		ans=max(ans,nans);
		return;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(o+1);
		a[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0);
	cout<<ans;
	return 0;
}
