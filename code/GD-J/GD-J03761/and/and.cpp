#include <bits/stdc++.h>
using namespace std;
int a[200005],ans=0;
bool v[200005];
int n,m;
void dfs(int cen,int sum) {
	if (cen==m) {
		ans=max(ans,sum);
	}
	int temp=sum;
	for (int i=1;i<=n;i++) {
		if (!v[i]) {
			v[i]=1;
			temp&=a[i]; 
			dfs(cen+1,temp);
			v[i]=0;
		}
	}
	return;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		v[i]=1;
		dfs(1,a[i]);
		v[i]=0;
	}
	cout<<ans;
	return 0;
}
