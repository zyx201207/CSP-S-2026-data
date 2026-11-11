#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	long long ans=0;
	for (int i=0;i<n;i++){
		long long current=a[i];
		for (int j=i+1;j<i+n;j++){
			current=current&a[j];
			ans=max(ans,current);
		}
	}
	cout << ans;
	return 0;
}
