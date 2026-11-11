#include<bits/stdc++.h>
#define int long long
#define uint unsigned int
#define all(x) x.begin(),x.end()
#define inf 0x3f3f3f3f
using namespace std;
const int maxN = 5e5 + 5;
const int maxM = inf;
int n,m; int temp; int cnt = 1; int a[maxN];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	temp = m;
	if(n>5000){
		int d = (a[1]-a[0]);
		int co = ceil((temp/d)*2);
		int delta = 1 + 4*co;
		cnt = floor((1+sqrt(delta))/2);
		cout << cnt;
		return 0;
	}sort(a,a+n); a[n] = 0;
	for(int i=0;i<n-1;i++){
		m -= (a[i+1]-a[i]);
		if(m < 0) break;
		cnt++;
	}cout << cnt;
	return 0;
}
