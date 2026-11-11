#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[200005],ans=0;
void sikao(int x,int step,int val) {
	if(step==m) {
		ans=max(ans,val);
		return ;
	}
	for(int i=x+1;i<=n+1;i++) {
		sikao(i,step,val);
	}
	for(int i=x+1;i<=n+1;i++) {
		sikao(i,step+1,val&a[x]);
	}
	return ;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	if(n<=2000) {
		sikao(1,0,(1<<31)-1);
		cout << ans;	
	}
	else{
		sort(a+1,a+n+1,greater<int>());
		if(m==1) cout << a[1];
		else if(m==n) {
			int sum=(1<<31)-1;
			for(int i=1;i<=n;i++) {
				sum&=a[i];
			}
			cout << sum;
		}
		else if(m==n-1) {
			for(int i=1;i<=n;i++) {
				int sum=(1<<31)-1;
				for(int j=1;j<=n;j++) {
					if(i!=j) sum&=a[j];
				}
				ans=max(ans,sum);
			}
			cout << ans;
		}
		else {
			int sum=(1<<31)-1;
			for(int i=1;i<=m;i++) {
				sum&=a[i];
			}
			cout << sum;
		}
	}
	return 0;
}
//Asking myself what atonement means.