#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N];
bool vis[N];
void dfs(int step,int sum) {
	if(step==m+1) {
		ans=max(ans,sum);
		return ;
	}
	if(sum==0) return ;
	for(int i=1; i<=n; i++) {
		if(vis[i]==0) {
			vis[i]=1;
			if(step==1) dfs(step+1,a[i]);
			else dfs(step+1,sum&a[i]);
			vis[i]=0;
		}
		else continue;
	}
	return ;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(m==1) {
		for(int i=1; i<=n; i++) {
			ans=max(ans,a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(m==2) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(m==n) {
		ans=a[1];
		for(int i=2; i<=n; i++) {
			ans=a[1]&a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(n<=20) {
		dfs(1,0);
		cout<<ans<<endl;
		return 0;
	}
	int x=n,flag=0;
	while(x!=1) {
		if(x%2!=0) {
			flag=1;
			break;
		}
		x/=2;
	}
	for(int i=1; i<=n; i++) {
		if(a[i]!=i-1) {
			flag=1;
			break;
		}
	}
	if(flag==0) {
		if(m*2>n) cout<<0<<endl;
		else {
			int t=m;
			while(t!=1) {
				if(t%2!=0) {
					flag=1;
					break;
				}
				t/=2;
			}
			if(flag==0) cout<<n-m<<endl;
			else cout<<0<<endl;
		}
	}
	else {
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=n-1; i>=n-m+1; i--) {
			ans=ans&a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
