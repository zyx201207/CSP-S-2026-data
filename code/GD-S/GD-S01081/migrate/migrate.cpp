#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, t, d, a[500005], r[500005], x[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>n>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1; i <= n; i++)cin>>x[i];
		for(int i = n; i >= 1; i--){
			if(i==n)r[i]=i;
			else{
				r[i]=r[i+1];
				while(r[i]>i&&a[r[i]]-x[i]>0)r[i]--;
			}
		}
		cout<<r[1]<<'\n';
	}
	return 0;
}
