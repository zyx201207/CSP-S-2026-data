#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200000+25];
int ans = -1;
signed main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	int maxx = 0;
	if (m == 1){
		for(int i = 1;i<=n;i++){
			maxx = max(maxx,a[i]);
		} 
		cout<<maxx;
		return 0;
	}
	for(int i = 1;i<(1<<2);i++){
		int sum = 0,cnt = 0;
		for(int j = 1;j<=n;j++){
			if ((1<<(j-1)) & i){
				if (sum == 0){
					cnt = a[j];
				} 
				else{
					cnt = cnt & a[j];
				}
				sum++;
			}
		}
		if (sum == m){
			ans = max(ans,cnt);
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
