#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int maxn=2e6+5;
const int mod=1e9+7;
int a[maxn];
int n,m;
int ans;
void dfs(int num,int cnt,int i){
	if(num==m){
		ans=max(ans,cnt);
		return ;
	}if(i>n)return ;
	dfs(num+1,((cnt==0)?(a[i]):cnt)&a[i],i+1);
	dfs(num,cnt,i+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		dfs(0,0,1);
		cout<<ans;
		return 0;
	}
	else if(n<=2000){
		if(m==1){
			sort(a+1,a+n+1,greater<int>());
			cout<<a[1];
			return 0;
		}
		else if(m==2){
			dfs(0,0,1);
			cout<<ans;
			return 0;
		}
		else{
			ans=a[1];
			for(int i=2;i<=n;i++)ans&=a[i];
			cout<<ans;
			return 0;
		}
	}
	else if(m==n-1){
		sort(a+1,a+n+1,greater<int>());
		ans=a[1];
		for(int i=1;i<=m;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	else{
		sort(a+1,a+n+1,greater<int>());
		ans=a[1];
		for(int i=1;i<=m;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	return 0;
}
