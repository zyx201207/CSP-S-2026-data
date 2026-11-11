#include <bits/stdc++.h>
using namespace std;

const int MAXN=500005;
int n;
long long m,a[MAXN],q[MAXN],p[MAXN];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>14000) {
		long long s=0;
		int ss=0;
		for(int i=2; i<=n; i++)
			a[i]-=a[1];
		a[1]=0;
		for(int i=1; i<=n; i++) {
			if(s+a[i]>m)break;
			else s+=a[i];
			ss++;
		}
		cout<<ss;
		return 0;
	}
	int ans=1;
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		q[i]=a[n]-a[i];
	}
	for(int i=1; i<=n; i++) {
		p[i]=p[i-1]+q[i];
	}
	for(int t=1; t<=n; t++)
		for(int i=t; i<=n; i++) {
			long long s=0;
			s=p[i-1]-p[t-1]-(q[i]-q[t-1])*(i-t);
			if(s<=m) {
				ans=max(ans,i-t+1);
			} else break;
		}
	cout<<ans;
	return 0;
}
//5 5
//1 2 4 8 9
//8 7 5 1 0
//8 15 20 21 21
//p[i-1]-q[i]*(r-l);
//5
//15-0=15
//2*5=10
//15-10=5
//
//10
//20-8=12
//2*1=2;
//12-2=10;
