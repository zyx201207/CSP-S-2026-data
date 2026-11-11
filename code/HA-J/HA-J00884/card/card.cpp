#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
int a[500005];
int cnt[300005];

void solve(int x) {
	int idx=x;
	while(x<n) {
		for(int i=n; i>=x; i--) {
			if(a[x]==a[i]) {
				cnt[a[i]]++;
				x=i+1;
			} else if(i==x) {
				cnt[a[i]]++;
				x++;
			}
		}
	}

	if(x==n) {
		cnt[a[n]]++;
	}
}

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	cin>>n>>m;

	bool f=1;

	for(int i=1; i<=n; i++) {
		cin>>a[i];
		cnt[a[i]]++;
		if(a[i-1]>a[i]) {
			f=0;
		}
	}

	if(f==1) {
		for(int i=1; i<=m; i++) {
			cnt[i]+=cnt[i-1];
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	
	memset(cnt,0,sizeof(cnt));

	for(int i=1; i<=n; i++) {
		solve(i);
	}

	for(int i=1; i<=m; i++) {
		cout<<cnt[i]<<" ";
	}
	return 0;
}
