#include <bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> a[i] >> b[i];
	long long ret = 0;
	int l = 1,r = n;
	long long cnt = a[1],cnt2 = a[n];
	while(l < r)
	{
		long long tot = min(cnt,cnt2);
		if(b[l] != b[r])ret += tot;
		cnt -= tot,cnt2 -= tot;
		if(cnt <= 0)l++,cnt = a[l];
		if(cnt2 <= 0)r--,cnt2 = a[r];
	}
	cout << ret;
	return 0;
}
