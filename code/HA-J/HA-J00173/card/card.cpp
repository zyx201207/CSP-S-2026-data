#include <bits/stdc++.h>
using namespace std;
const int N=500002,M=300002;
int n,m,a[N],aa[N],next_[N],sum[M];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool flag=1;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (i>1 && a[i]>a[i-1]) flag=0;
	}
	if (flag) {
		for (int i=1;i<=n;i++) sum[a[i]]++;
		for (int i=1;i<=m;i++) {
			sum[i]+=sum[i-1];
			cout<<sum[i]<<' ';
		}
		return 0;
	}
	if (m==1) {
		cout<<n;
		return 0;
	}
//	int nn=0;
//	for (int i=1;i<=n;i++) {
//		if (a[i]==a[i-1]) continue;
//		aa[++nn]=a[i];
//	}
//	n=nn;
//	for (int i=1;i<=n;i++) a[i]=aa[i];
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++) {
			if (a[j]==a[i]) {
				next_[i]=j;
				break;
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++) {
			if (next_[j]!=0) j=next_[j]-1;
			else sum[a[j]]++;
		}
	}
	for (int i=1;i<=m;i++) cout<<sum[i]<<' ';
	return 0;
}
