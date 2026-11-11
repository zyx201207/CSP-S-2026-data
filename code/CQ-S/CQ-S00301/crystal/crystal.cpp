/*
下午我先吃德芙。
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
德芙巧克力真好吃！
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const long long INF=1e12+5;
int n;
long long m,a[N],ans;
bool check(long long mid) {
	long long sum=0;
	for (int i=1;i<=mid;i++) {
		sum+=abs(a[mid]-a[i]);
	}
	long long res=sum;
	for (int i=2;i+mid-1<=n;i++) {
		int j=i+mid-1;
		sum+=(a[j]-a[j-1])*(mid-1)-(a[j-1]-a[i-1]);
		res=min(res,sum);
	}
	return res<=m;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=n;
	while (l<=r) {
		long long mid=(l+r)>>1;
		if (check(mid)) {
			l=mid+1;
		} 
		else {
			r=mid-1;
		}
	} 
	cout << r;
	return 0;
}
/*
5 8
-3 -1 2 2 7
结论：中位数 
*/
