#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],cnt,ans[N],s[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>=a[i-1]) {
			cnt++;
		}
	}
	if(n==cnt) {
		for(int i=1; i<=n; i++) {
			memset(b,0,sizeof(b));
			for(int j=i; j<=n; j++) {
				b[a[j]]++;
			}
			for(int j=1; j<=m; j++) {
				if(b[j]) {
					ans[j]++;
				}
			}
		}
		for(int i=1; i<=m; i++) {
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1; i<=n; i++) {
		memset(s,0,sizeof(s));
		memset(b,0,sizeof(b));
		int x=1;
		for(int j=i; j<=n; j++) {
			bool f=false;
			for(int k=1; k<=j; k++) {
				if(!f) {
					if(s[k]==a[j]) {
						f=true;
						x=k;
						s[k]=0;
					}
				} else {
					s[k]=0;
				}
			}
			s[x]=a[j];
			x++;
		}
		for(int j=1; j<=x; j++) {
			b[s[j]]++;
		}
		for(int j=1; j<=m; j++) {
			if(b[j]) {
				ans[j]++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
