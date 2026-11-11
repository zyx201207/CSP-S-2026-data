#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005],nxt[2000005],lst[2000005];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i = 1; i<=n; i++) {
			cin>>a[i];
		}
		int j;
		j = 1;
		for(int i = 1; i<=n; i++) {
			while(j<n && a[j+1]-a[i]<=d) {
				j++;
			}
			nxt[i] = j;
		}
		j = n;
		for(int i = n; i; i--) {
			while(j>1 && a[i]-a[j-1]<=d) {
				j--;
			}
			lst[i] = j;
		}
		int ans;
		ans = 0;
		if(13<=c && c<=14) {
			for(int i = 1;i<=n;i++){
				int id1,id2;
				id1 = lower_bound(lst+i+1,lst+n+1,nxt[i]-1)-lst;
				id2 = lower_bound(lst+i+1,lst+n+1,nxt[i])-lst;
				ans = ans+id2-id1;
			}
		} else {
			for(int i = 1; i<=n; i++) {
				int l,r,ok1,ok0;
				l = nxt[i]+1;
				r = nxt[nxt[i]];
				ok1 = 1;
				ok0 = 1;
				while(l<=r && l<=n) {
					int id1,id2;
					id1 = lower_bound(lst+l,lst+r+1,l-2)-lst;
					id2 = lower_bound(lst+l,lst+r+1,l-1)-lst;
					if(ok1 == 1) {
						ans = ans+id2-id1;
					}
					if(ok0 == 2) {
						ans = ans+r-id2+1;
					}
					int n0,n1;
					if(lst[r]<l-2) {
						n0 = 3;
					} else if(lst[r] == l-2) {
						n0 = ok1*2;
					} else {
						n0 = ok0;
					}
					if(lst[r-1]<l-2) {
						n1 = 3;
					} else if(lst[r-1] == l-2) {
						n1 = ok1*2;
					} else {
						n1 = ok0;
					}
					ok0 = n0;
					ok1 = n1;
					l = r+1;
					r = nxt[r];
				}
			}
		}
		cout<<ans<<"\n";
		for(int i = 1; i<=n; i++) {
			a[i] = 0;
			nxt[i] = 0;
			lst[i] = 0;
		}
	}
	return 0;
}


