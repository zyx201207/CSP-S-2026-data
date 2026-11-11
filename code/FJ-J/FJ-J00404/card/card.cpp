#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	vector<long long> a(n),ans(m+1,0);
	vector<bool> t;
	for(long long& i:a) cin >> i;
	for(long long i=0;i<n;i++) {
		t=vector<bool>(m+1,false);
		for(long long j=i;j<n;j++) {
			if(t[a[j]]) {
				t=vector<bool>(m+1,false);
				t[a[j]]=true;
				continue;
			}
			t[a[j]]=true;
		}
		for(long long j=1;j<=m;j++) {
			if(t[j]) {
				ans[j]++;
			}
		}
	}
	for(long long i=1;i<=m;i++) {
		cout << ans[i] << ' ';
	}
	return 0;
} 
