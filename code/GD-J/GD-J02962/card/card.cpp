#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[500001],c[300001],ans[300001];

signed main(){
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	
	for (int i = 1;i <= n;i ++){
		memset (c,0,sizeof c);
		for (int j = i;j <= n;j ++){
			if (c[a[j]] == 0){
				c[a[j]] = j;
				ans[a[j]] ++;
			}
			else{
				for (int k = 1;k <= m;k ++){
					if (c[a[j]] < c[k] && c[k] < j){
						c[k] = 0;
						ans[k] --;
					}
				}
			}
		}
	}
	for (int i = 1;i <= m;i ++) cout << ans[i] << " ";
//	for (int i = n;i >= 1;i --){
//		if (c[a[i]] == 0) c[a[i]] = i,ans[a[i]] += i;
//		else{
//			for (int j = 1;j <= n;j ++){
//				if (i < c[j] && c[j] < c[a[i]]){
//					c[j] = 0;
//					ans[j] -= i;
//				}
//			}
//			c[a[i]] = i;
//		}
//	} 
//	
//	for (int i = 1;i <= m;i ++){
//		cout << ans[i] << " ";
//	}
	return 0;
}

