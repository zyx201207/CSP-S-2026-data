#include <bits/stdc++.h>
using namespace std;

int n, m;
unsigned int a[200100];
bool c[200100];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		c[i]=1;
	}
	unsigned int ans=0;
	for(int i=30;i>=0;--i) {
		int cnt=0;
		vector<int> vec;
		for(int j=1;j<=n;++j) {
			if(c[j] && (a[j]>>i)&1) cnt++;
			else vec.push_back(j);
		}
		if(cnt>=m) {
			ans|=(1<<i);
			for(int j:vec) c[j]=0;
		}
	}
	cout<<ans;
	return 0;
}
