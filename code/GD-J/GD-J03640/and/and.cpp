#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 0 ; i < n ; i ++){
		cin >> a[i];
	}
	sort(a,a+n);
	unsigned long long ans=0;
	ans=a[n-m];
	for (int i = n-m+1 ; i < n ; i ++){
		ans=ans&a[i];
	}
	cout << ans;
	return 0;
}
