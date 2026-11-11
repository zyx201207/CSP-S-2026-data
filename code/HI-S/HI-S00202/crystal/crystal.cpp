#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],ans;
int b[500005],maxn=-0x3f3f3f3f,minn=0x3f3f3f3f,d=0x3f3f3f3f;
bool c=1;
bool cmp(int x,int y)
{
	return x < y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(d == 0x3f3f3f3f && i != 1) d = a[i] - a[i-1];
		if(i != 1 && a[i]-a[i-1] != d) c = 0; 
		maxn = max(maxn,a[i]);
		minn = min(minn,a[i]);
	}
	if(c == 1){
		while(m >= 0){
			m -= (++ans) * d;
		}
		cout << ans;
		return 0;
	}
	for(int k=minn;k<=maxn;k++){
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			b[i] = a[i]<=k ? k-a[i] : 0x3f3f3f3f;
		}
		sort(b+1,b+n+1,cmp);
		int sum = 0,cnt = 0;
		for(int i=1;i<=n;i++){
			sum += b[i];
			if(sum > m) break;
			cnt++;
		}
		ans = max(ans,cnt);
	}
	cout << ans;
	return 0;
}
