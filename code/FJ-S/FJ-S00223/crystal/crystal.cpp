#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
long long b[1000001];
long long n,m;
long long ans;
void dfs(long long s[10000001],long long x){
	if(x<0){
		return;
	}
	long long c=1;
	for(int i=1;i<=n;i++){
		if(i!=n&&s[i]==s[i+1]){
			c++;
		}
		s[i]++;
		dfs(s,x-1);
		s[i]--;
	}
	ans=max(c,ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	dfs(a,m);
	cout<<ans;
	return 0;
} 
