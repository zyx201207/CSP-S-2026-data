#include <bits/stdc++.h>
using namespace std;
int a[200005],c[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		c[i] = 1;
	}
	long long ans = 0;
	for(int i = 30;i >= 0;i--){
		int sum = 0;
		for(int j = 1;j <= n;j++){
			if((a[j] & (1 << i)) != 0 && c[j]){
				sum++;
			}
		}
		if(sum < m) continue;
		for(int j = 1;j <= n;j++){
			if((a[j] & (1 << i)) == 0){
				c[j]=0;
			}
		}
		ans += 1 << i;
	}
	cout << ans; 
	return 0;
}

