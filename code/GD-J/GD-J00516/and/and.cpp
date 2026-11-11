#include<bits/stdc++.h>
#define int long long
using namespace std;
const int lim = (1ll << 30) - 1;
int n,m,ans = 0,a[200005];

void dfs(int now,int cnt,int Ans){
	if(now > n){
		if(cnt != m) return;
		ans = max(ans,Ans);
		return;
	}
	dfs(now + 1,cnt + 1,Ans & a[now]);
	dfs(now + 1,cnt,Ans);
	return;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;++i)
		scanf("%lld",&a[i]);
	if(n <= 20) dfs(1,0,lim);
	else if(n <= 2000){
		if(m == 1)
			for(int i = 1;i <= n;++i)
				ans = max(ans,a[i]);
		if(m == n)
			for(int i = 1;i <= n;++i)
				ans &= a[i];
		if(m == 2)
			for(int i = 1;i <= n;++i)
				for(int j = i + 1;j <= n;++j)
					ans = max(ans,a[i] & a[j]);
	}
	else{
		int maxn = 0;
		for(int i = 1;i <= n;++i)
			maxn = max(maxn,a[i]);
		if(maxn > 4){
			sort(a + 1,a + n + 1,greater<int>());
			for(int i = 1;i <= m;++i)
				ans &= a[i];
		}
		else{
			int cnt[5] = {};
			for(int i = 1;i <= n;++i)
				cnt[a[i]]++;
			if(cnt[4] >= m) ans = 4;
			else if(cnt[3] >= m) ans = 3;
			else if(cnt[3] + cnt[2] >= m) ans = 2;
			else if(cnt[3] + cnt[1] >= m) ans = 1;
		}
	}
	printf("%lld\n",ans);
    return 0;
}
/*

*/
