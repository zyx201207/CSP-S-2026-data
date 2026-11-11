#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,a[200001];
long long ans=-1e18;
vector<int> vec;
void dfs(int x,int cnt){
	if(x==n && cnt!=m)return;
	if(cnt==m){
		int now=vec[0];
		for(int i=1;i<vec.size();i++){
			now&=vec[i];
		}
		ans=max(ans,(long long)now);
		return;
	}
	for(int i=x+1;i<=n;i++){
		vec.push_back(a[i]);
		dfs(i,cnt+1);
		vec.pop_back();
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and4.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,(long long)a[i]);
		}
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}
	else if(n<=20 || m==2){
		for(int i=1;i<n;i++){
			vec.push_back(a[i]);
			dfs(i,1);
			vec.pop_back();
		}
	}
	else if(log2(n)-(double)__lg(n)==(double)0){
		sort(a+1,a+n+1,greater<int>());
		ans=a[m];
	}else{
		pair<int,int> op[200005];
		for(int i=1;i<=n;i++){
			op[i]={__builtin_popcount(a[i]),a[i]};
		}
		sort(op+1,op+n+1,greater<pair<int,int>>());
		ans=op[m].second;
	}
	cout<<ans;
}
