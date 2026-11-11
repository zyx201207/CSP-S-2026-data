#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
queue<int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int ans = 0;
	for (int i=1;i<=n;++i){
		int sz = q.size(),f=-1;
		if (sz) m -= sz*(a[i]-q.back());
	//	printf("i: %lld, pre_m: %lld ,pre_size:%lld, a[i]-q_bk : %lld, ",i,m,sz,f);
		while(m < 0 && !q.empty()) {
			int tp = q.front();
			m += a[i]-tp;
	//		printf("dlt: %lld | now_m: %lld,",tp,m);
			
			q.pop();
		}
		q.push(a[i]);
	//	printf("m: %lld\n",m);
		ans = max(ans,(long long)q.size());
	}
	cout << ans;
	return 0;
}
//RP++
/*
5 5 
1 2 4 8 9 

*/
