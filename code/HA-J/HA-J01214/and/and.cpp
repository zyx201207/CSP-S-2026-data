#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
bool p[200010];
int main() {
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	long long ans=0;
	for(int i=30; i>=0; i--) {
		long long u=1<<i;
		int cnt=0;
		for(int j=1; j<=n; j++) {
			if(p[j]==0&&a[j]&u)cnt++;
		}
		if(cnt>=m) {
			ans+=u;
			for(int j=1; j<=n; j++) {
				if(p[j]==0&&((a[j]&u)==0))p[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
