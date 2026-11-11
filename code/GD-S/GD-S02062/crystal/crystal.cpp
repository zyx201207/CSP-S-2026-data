#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n;
long long m,a[N];
long long min_i=1;
long long cnt[N]={0x3f3f3f3f};
long long ans[N]={0};
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	if (m==0) {
		cout<<1;return 0;
	}
	int summ=0;
	//计算出一个与其他数距离最小的 
	for (int i=1;i<=n;i++) {
		int ans=0;
		for (int j=1;j<=n;j++) {
			ans+=abs(a[i]-a[j]);
			if (a[i]-a[j]>=0){
			cnt[j]=a[i]-a[j];}else cnt[j]=0x3f3f3f3f;
		} 
	sort(cnt+1,cnt+n+1);
	int k=1,sum=0,m1=m;
	while (cnt[k]<=m1){
		m1-=cnt[k];k++;sum++;
	}summ=max(sum,summ);
	}

	cout<<summ;
	return 0;
} 
