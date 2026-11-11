#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+9;
int a[N];
void solved(){
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	int ans=a[n];
	if(m==1){
		cout << a[n];
		return;
	}
	if(m==n){
		for(int i=n;i>=1;i--)ans=ans&a[i];
		cout << ans;
		return;
	}
	for(int i=n;i>=n-m+1;i--){
		ans=ans&a[i];
	}
	cout << ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	int t; cin >> t; while(t--)
	solved();
	return 0;
}

