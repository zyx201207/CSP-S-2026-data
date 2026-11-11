//GZ-J00466 遵义市第十九中学 吴国懋
#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long zh=0,mx=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m==1) cout<<a[1];
	else if(m==n) {
		zh=a[1];
		for(int i=1; i<=n; i++) {
			zh=zh&a[i];
		}
		cout<<zh;
	} else if(m==2) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				zh=a[i]&a[j];
				if(zh>mx&&i!=j)
					mx=zh;
			}
		}
		cout<<mx;
	} else if(m==n-1) {
		zh=a[1];
		for(int i=1; i<=n-1; i++) {
			zh=zh&a[i];
		}
		cout<<zh;
	} else {
		zh=a[1];
		for(int i=1; i<=m; i++) {
			zh=zh&a[i];
			
		}
		cout<<zh;
	}
	return 0;
}
