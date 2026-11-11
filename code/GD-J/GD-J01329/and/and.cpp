#include<bits/stdc++.h>
using namespace std;

#define int long long
//(double)(clock()-start)/CLOCKS_PER_SEC

const int N=2*1e5+3;

clock_t start=clock();
int n,m,ans=0;
int a[N];
stack<int> s,aaa;

void dfs(int dep,int res,int cnt) {
	if(cnt==m) {
		ans=max(ans,res);
		if(ans==res) aaa=s;
		return;
	}
	if(dep==n+1) return;
	if((double)(clock()-start)/CLOCKS_PER_SEC>0.9) return;
	
	dfs(dep+1,(res==0?a[dep]:res&a[dep]),cnt+1);
	dfs(dep+1,res,cnt);
}

signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if(m==1) {
		cout<<*max_element(a+1,a+1+n);
		return 0;
	}
	if(m==n) {
		int ans=a[1];
		for(int i=2;i<=n;i++) {
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	if((double)(clock()-start)/CLOCKS_PER_SEC>0.9) {
		sort(a+1,a+1+n);
		cout<<max(ans,a[m]);
	}
	else cout<<ans;
}
