#include<bits/stdc++.h>
using namespace std;
#define int long long
int sum[500005],a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int mn = 0;
	for (int i = 1;i <= n;i++)
		cin >> a[i],mn = min(mn,a[i]);
	for (int i = 1;i <= n;i++)
		a[i] = a[i] - mn;
	sort(a + 1,a + n + 1);
	bool flag = 1;
	for (int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
		if(i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])
			flag = 0;
	}
	if (flag){
		int cnt = a[2] - a[1],tmp = m,ans = 1;
		for (int i = 1;i <= n/2;i++){
			if (tmp >= 2*cnt) ans += 2,tmp -= 2*cnt;
			else if (tmp >= cnt) ans++,tmp -= cnt;
			else break; 
			cnt += a[2] - a[1];
		} 
		printf("%lld",min(ans,n));
		return 0;
	}
	//for (int i = 1;i <= n;i++)
	//	printf("xxx %lld ",m);
	//for (int i = 1;i <= n;i++)
	//	printf("xxx %lld ",m);
	for (int i = 1;i <= n;i++){
		for (int l = 1;l <= i;l++){
			for (int r = i;r <= n;r++){
				int cnt = 0;
				for (int j = l;j <= r;j++)
					cnt += abs(a[i] - a[j]);
				if (cnt > m) break;
				if(cnt <= m)
					ans = max(ans,r - l + 1);
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
