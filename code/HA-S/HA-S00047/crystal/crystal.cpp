#include<bits/stdc++.h>
using namespace std;
#define len first
#define cost second
long long n,m;
bool check(vector<long long>&num,vector<long long>&pre,long long k) {
	for(int i=0; i<n-k; i++) {
		long long sum=0,maxx=-1;
		sum+=num[i+k]*k-(pre[i+k]-pre[i]);
		if(sum<=m) {
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<long long> num(n),pre(n);
	long long adv = 0;
	for(long long i=0; i<n; i++) {
		cin >> num[i];
	}
	sort(num.begin(),num.end());
	pre[0]=num[0];
	for(long long i=1; i<n; i++) {
		pre[i]+=pre[i-1]+num[i];
	}
	long long l=0,r=n;
	while(l+1<r) {
		long long mid=(l+r)/2;
		if(check(num,pre,mid)) {
			l=mid;
		} else {
			r=mid;
		}
	}
	cout << l;
	return 0;
}
