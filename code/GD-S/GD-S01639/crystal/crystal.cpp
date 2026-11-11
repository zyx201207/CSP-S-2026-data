#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =5e5+10;
//const int maxm =1e18+10;
ll m;
int n;
int a[maxn];
//int dp[maxn];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	int mid=0,mn=INT_MAX,xm;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		//mid+=a[i];
	}
	//mid/=n;
//	for(int i=1;i<=n;i++) {
//		int x=abs(a[i]-mid);
//		if(mn>x) xm=a[i];
//	}
//	mid=xm;
	sort(a+1,a+1+n);
	int mx=0;
	int nm=m;
	for(int i=1;i<=n;i++) {
		mid=a[i];
		int sum=1;
		nm=m;
		for(int j=i-1;j>=1&&nm>0;j--) {
			if(nm<abs(mid-a[j])) continue;
			sum++;
			nm-=abs(mid-a[j]);
			//cout << nm<<' ';
		} 
		mx=max(mx,sum);
	}
	cout << mx;
return 0;
} 
