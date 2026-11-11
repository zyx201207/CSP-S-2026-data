#include<iostream>
#include<vector>
#define int unsigned long long
using namespace std;
int MX = LLONG_MAX;
int n,m,ans;
vector<int> a;
void dfs(int pos,int num,int sum) {
	if(pos>n&&num==m) {
		ans=max(ans,sum);
		return ;
	}
	if(num+n-pos+1<m||num>m) {
		return ;
	}
	dfs(pos+1,num+1,sum&a[pos]);
	dfs(pos+1,num,sum);
	return ;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;

	if(m==1) {
		int ans = 0;
		for(int i=1; i<=n; i++) {
			int d;
			cin>>d;
			ans = max(ans,d);
		}
		cout<<ans;
		return 0;
	}

	if(m==n) {
		for(int i=1; i<=n; i++) {
			int d;
			cin>>d;
			MX&=d;
		}
		cout<<MX;
		return 0;
	}

	if(m==n-1) {
		a.resize(n+1);
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			MX&=a[i];
		}
		for(int i=1; i<=n; i++) {
			ans=max(ans,MX|a[i]);
		}
		cout<<ans;
		return 0;
	}

	a.resize(n+1);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(1,0,MX);
	cout<<ans;
	return 0;
}

