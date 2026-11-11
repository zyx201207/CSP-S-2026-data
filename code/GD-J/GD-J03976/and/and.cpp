#include <bits/stdc++.h>
using namespace std;

long long a[200050];

int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	ans = a[1];
	if(m == 2) {
		ans &= a[2];
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=m;i++)
		ans &= a[i];
	cout<<ans;
	return 0;
}
