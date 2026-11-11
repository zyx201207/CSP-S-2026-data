#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=2E5+5;
ll n,m;
ll a[MAXN];
vector<ll>v;
long long ans;
void dfs(int dep){//当前正在决策第dep个数字 
	if(v.size()==m){
		long long res=v[0];
		for(int i=1;i<v.size();++i)res=res&v[i];
		ans=max(ans,res);
		return ;
	}
	if(dep==n+1)return ;
	v.push_back(a[dep]);
	dfs(dep+1);
	v.pop_back();
	dfs(dep+1); 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n<=20){//范围支持暴力dfs
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;++i)ans=max(ans,a[i]);
		cout<<ans<<endl;
		return 0; 
	}
	if(m==n){
		for(int i=1;i<=n;++i)ans=ans&a[i];
		cout<<ans<<endl;
		return 0;
	}
	if(m==2&&n<=5000){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j)ans=max(ans,a[i]&a[j]);
		}
		cout<<ans<<endl;
		return 0; 
	}
	if(m==n-1&&n<=5000){
		ll res;
		res=a[2];
		for(int i=3;i<=n;++i)res&=a[i];
		ans=res;
		for(int i=2;i<=n;++i){//选择一个不&
			res=a[1];
			for(int j=1;j<=n;++j){
				if(j==i)continue;
				res&=a[j];
			}
			ans=max(ans,res);
		}
		cout<<ans<<endl;
	}
	sort(a+1,a+1+n,greater<int>());
	ans=a[1];
	for(int i=2;i<=m;++i)ans&=a[i];
	cout<<ans<<endl;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
