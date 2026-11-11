#include <bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

int n,m;
int a[N];
int ans;

bool cmp(int x,int y){
	return x < y;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;++i) cin >> a[i];
	sort(a+1,a+1+n,cmp);
	
	ans = 1;
	int l=1,len=1,now=0; //最左侧 长度 已用能量 
	for (int i=2;i<=n;++i){
		while (l < i && now + (a[i] - a[i-1])*len > m){
			now -= a[i-1] - a[l];
			l++;
			len--;
		} 
		now += (a[i] - a[i-1]) * len;
		len++;
		ans = max(ans,len);
	}
	cout << ans;
	
	
	
	return 0;
}




