#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,cnt=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int sum=0;
	for(int i=m;i<=n;i++){
		sum=a[i-m];
		for(int o=i-m+1;o<i;o++){
			sum=a[o]&sum;
		}
		cnt=max(cnt,sum);
	}
	cout<<cnt;
	return 0;
}
