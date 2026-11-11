#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1;
long long a[200005];
bool f[200005];
vector<long long> v;
void dfs(int x){
	if (x>m){
		long long sum=v[0];
		for (int i=1;i<v.size();i++){
			sum=sum&v[i];
		}
		ans=max(sum,ans);
		return ;
	}
	for (int i=1;i<=n;i++){
		if (f[i]==0){
			v.push_back(a[i]);
			f[i]=1;
			dfs(x+1);
			v.pop_back();
			f[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
