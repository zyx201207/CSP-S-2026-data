#include <bits/stdc++.h>
using namespace std;
const int N=500002;
int n;
long long m,a[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1,sum=1;
	for (int i=2;i<=n;i++) {
		while (m-sum*(a[i]-a[i-1])<0 && sum) {
			m+=a[i-1]-a[i-sum];
			sum--;
		}
		m-=sum*(a[i]-a[i-1]);
		sum++;
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
/*
3 5
4 8 9
4 5
2 4 8 9
5 5
1 2 4 8 9
*/