#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
vector<long long> a;
bool check(long long x){
	long long now = 0;
	long long mmin = 4000000000000000000;
	vector<long long> k;
	int head = 0;
	for(int i = 0; i < x; i++){
		long long y;
		y = a[i];
		k.push_back(y);
		now = now + a[x - 1] - a[i];
	}
	mmin = min(mmin, now); 
	for(int i = x; i < n; i++){
		long long y;
		y = a[i];
		now = now + x * (a[i] - k.back());
		k.push_back(y);
		now = now - y + k[head];
		head++;
		mmin = min(mmin, now);
	}
	return mmin <= m;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		long long x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	long long l = 1ll;
	long long r = n;
	while(l < r){
		long long mid = (l + r + 1) / 2;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid - 1ll;
		}
	}
	cout << m;
	return 0;
} 
