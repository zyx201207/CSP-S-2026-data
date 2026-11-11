#include <bits/stdc++.h>
using namespace std;
struct T {
	long long x;
	int s[40];
	bool f;
} a[200010];
int l=31;
void zh(int i) {
	int j=31;
	long long x=a[i].x;
	while(x) {
		a[i].s[j--]=x%2;
		x/=2;
	}
	l=min(l,j);
	return;
}
int n,m;
long long sum=-1;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int nn=n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].x;
		a[i].f=false;
		zh(i);
	}
	vector<int> z;
	for(; l<=31; l++) {
		z.clear();
		for(int i=1; i<=n; i++) {
			if(a[i].f) continue;
			if(a[i].s[l]==0) z.push_back(i);
		}
		if(nn-z.size()>=m) {
			for(int i:z) a[i].f=true;
			nn-=z.size();
		}
		if(nn==m) break;
	}
	for(int i=1; i<=n; i++) {
		if(a[i].f) continue;
		if(sum==-1) sum=a[i].x;
		else sum=sum&a[i].x;
	}
	cout<<sum;
	return 0;
}
