#include<bits/stdc++.h>
using namespace std;
const int N = 510000;
long long a[N];
queue<long long> q;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n , m;
	cin >> n >> m;
	for(long long i = 1;i <= n;++ i)
		cin >> a[i];
	sort(a + 1 , a + 1 + n);
	long long ans = 0 , sum = 0;
	if(a[1] <= m)
		ans = 1 , q.push(a[1]);
	for(long long i = 2;i <= n;++ i){
		long long t = (a[i] - a[i - 1]);
		sum += t * q.size();
		if(sum > m)
			while(!q.empty() && sum > m)
				q.pop() , sum -= (a[i] - q.front());
		q.push(a[i]);
		ans = max((long long)(q.size()) , ans);
	}
	cout << ans;
	return 0;
}