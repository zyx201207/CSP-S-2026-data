#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0,a[200010];
vector<int>s[50];
bool v[200010];
void dfs(int x){
	if(x<0) return;
	int sum=0;
	for(int i=0;i<s[x].size();i++) sum+=v[s[x][i]];
	if(sum>=m){
		ans+=(1<<x);
		for(int i=1;i<=n;i++){
			int k=lower_bound(s[x].begin(),s[x].end(),i)-s[x].begin();
			if(s[x][k]!=i) v[i]=0;
		}
	}
	dfs(x-1);
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;(1<<j)<=a[i];j++){
			if((1<<j)&a[i]) s[j].push_back(i);
		}
	}
	for(int i=40;i>=0;i--){
		if(s[i].size()>=m){
			for(int j=0;j<s[i].size();j++) v[s[i][j]]=1;
			ans+=(1<<i);
			dfs(i-1);
			break;
		}
	}
	cout<<ans;
	return 0;
}
//9:19  100
