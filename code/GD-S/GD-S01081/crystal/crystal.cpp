#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], s[500005], ma=INT_MIN;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	int f=0;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])f=1;
	}
	if(!f){
		for(int i = 1; i <= n; i++){
			if(i*a[i]-s[i]>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++)s[i]=s[i-1]+a[i];
	int l=1, r=1;
	while(r<=n){
		while(abs((r-l+1)*a[r])-abs(s[r]-s[l-1])<=m&&r<=n)r++;
		ma=max(ma, r-l);
		while(l<=r&&abs((r-l+1)*a[r])-abs(s[r]-s[l-1])>m)l++;
	}
//	for(int i = 1; i <= n; i++){
//		int l=, r=
//		while(l<=r&&(r-l+1)*a[r]<=m){
//			
//		}
//		
//	}
	cout<<ma;
	return 0;
}
