#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans,s;
int a[500005];
int sum[500005];
int u;
signed main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
	}
	ans=1;
	s=1;
	int j=1;
	for(int i=2;i<=n;i++) {
		//cout<<a[i]<<" ";
		s++;
		if(a[i]==a[i-1]) {
			ans=max(ans,s);
			continue;
		}
		u=a[i]*(i-j+1)-(sum[i]-sum[j-1]);
		//cout<<a[i]<<" "<<sum[i]-sum[j-1]<<endl;
		while(j<i&&u>m) {
			j++;
			s--;
			u=a[i]*(i-j+1)-(sum[i]-sum[j-1]);
		}
		ans=max(ans,s);
	}
	//cout<<endl;
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
