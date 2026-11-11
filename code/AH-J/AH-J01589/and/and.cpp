#include<bits/stdc++.h> 
using namespace std;
int a[200005];
long long ans=-1;
void dfs(int n,int m,int step,int sum,long long summ) {
	if (sum==m) {
		ans=max(ans,summ);
		return;
	}
	if (step==n+1) return;
	dfs(n,m,step+1,sum+1,summ&a[step]);
	dfs(n,m,step+1,sum,summ);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if (m==1) {
		int mx=-1;
		for (int i=1;i<=n;i++) {
			int x;
			cin>>x;
			mx=max(mx,x);
		}
		cout<<mx;
	}
	else if (m==n){
		int x;
		cin>>x;
		int k=x;
		for (int i=2;i<=n;i++) {
			cin>>x;
			k&=x;
		}
		cout<<k;
	}
	else if (m==2) {
		for (int i=1;i<=n;i++) {
			cin>>a[i];
		}
		int mx=-1;
		for (int i=1;i<=n;i++) {
			for (int j=i+1;j<=n;j++) {
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}
	else {
		for (int i=1;i<=n;i++) {
			cin>>a[i];
		}
		dfs(n,m,1,0,0xffffffff);
		cout<<ans;
	}
}
