#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

priority_queue<long long,vector<long long>,less<long long> > q;
int n;
long long m;
vector<long long> s;

bool check(int x) {
	int l = (x-1)/2;
	for (int i=0;i<=n-x;i++) {
		long long cost;
		cost = (s[i+l+1]-s[i])-(s[i+x]-s[i+x-l-1]);
		if (cost<=m) {
			cout << x << ' ' << i << ' ' << cost << endl;
			return true;
		}
	}
	return false;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a;
	cin >> n >> m;
	for (int i=0;i<n;i++) {
		cin >> a;
		q.push(a);
	}
	s.push_back(0);
	for (int i=0;i<n;i++) {
		s.push_back(s.back()+q.top());
		q.pop();
	}
	int l=0,r=n,mid;
	while (l<r-1) {
		mid = (l+r)/2;
		cout << l << ' ' << r << ' ' << mid << endl;
		if (check(mid)) {
			l=mid;
		} else {
			r=mid-1;
		}
	}
	cout << l;
	return 0;
}
