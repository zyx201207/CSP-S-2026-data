#include<bits/stdc++.h>
using namespace std;
using t64 = long long;
t64 n,m;
t64 a[500005];
t64 c[500005];
t64 ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		t64 b = m;
		t64 sum = 0;
		for(int j=i;j>=1;j--){
			if(b>=a[i]-a[j]){
				sum ++;
				b-=(a[i]-a[j]);
			}
		}
		ans=max(ans,sum);
	}
	cout << ans;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
