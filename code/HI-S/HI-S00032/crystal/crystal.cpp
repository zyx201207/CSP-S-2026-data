#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+10;

#define ll long long

int n;
ll a[N], m, s[N];

bool chk(int l, int r, ll t) {
	ll v=s[r]-s[l-1];
	return (t*(r-l+1)-v)<=m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	s[0]=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;) {
		int j=i;
		while(j+1<=n&&a[j+1]==a[j])++j;
		int q=j-i+1;
		if(i==1) {
			ans=max(ans, q);	
			i=j+1;
			continue;
		}
		if(chk(1,i-1,a[i])) {
			ans=max(ans, j);
			i=j+1;
			continue;
		}
		if(!chk(i-1,i-1,a[i])) {
			ans=max(ans, q);
			i=j+1;
			continue;
		} 
		int l=1,r=i, k;
		while(r>l) {
			int mid=(l+r)>>1;
			if(chk(mid,i-1,a[i])) {
				r=mid, k=mid; 
			}else {
				l=mid+1;
			} 
		}
		q+=(i-1)-k+1;
		ans=max(ans, q);
		i=j+1;
	}
	cout<<ans;
	return 0;
}

//14:49 DONE
//orange.
