#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[500005];
LL tr2345[500005];
LL res[500005];
LL n,m;
LL f(LL l,LL r) {
	LL res=0;
	for(int i=1;i<=r-l;++i) {
		res+=tr2345[l+i]*i;
	}
	return res;
}
LL g(LL r) {
	return (r+1)*(r)/2;
}
LL h(LL r,LL ccc) {
	return (ccc+ccc*r)*r/2;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
	}
	bool bo1=1,bo2=1;
	if(a[1]!=1) bo1=0;
	LL cccc=0;
	for(int i=2;i<=n-1;++i) {
		if(a[i]!=i) bo1=0;
		if(a[i]-a[i-1]!=a[i+1]-a[i]) bo2=0;
		cccc=a[i]-a[i-1];
	}
	if(a[n]!=n) bo1=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) {
		tr2345[i]=a[i]-a[i-1];
	}
	LL sum=0;
	tr2345[1]=0;
	if(bo1) {
		LL dfs=0;
		for(int i=1;i<=n;i++) {
			if(g(i)>m) {
				dfs=i;
				break;
			}
		}
		cout<<dfs;
	}
	else if(bo2) {
		LL dfs=0;
		for(int i=1;i<=n;++i) {
			if(h(i,cccc)>m) {
				dfs=i;
				break;
			}
		}
		cout<<dfs;
	}
	else {
		LL i=1,j=1;
		LL dfs=0;
		while(j<=n) {
			while(j<=n && f(i,j)<=m) ++j;
			dfs=max(dfs,j-i);
			while(f(i,j)>m) ++i;
		}
		cout<<dfs;
	}
	return 0;
}
/*
	for(int i=1;i<=n;++i) {
		res[i]=res[i-1]+tr2345[i];
		a[i]=a[i-1]+res[i];
		sum+=tr2345[i];
		cout<<tr2345[i]<<" ";
	}
	cout<<"\nRes:";
	LL ssum=0;
	for(int i=1;i<=n;++i) {
		ssum+=res[i];
		cout<<res[i]<<" ";
	}
	cout<<endl;
	sum=0;
	LL dfs=0;
	int i=1,j=1;
	while(j<=n) {
		while(j<=n && a[j]-a[i-1]<=m) ++j;
		dfs=max(dfs,(LL)(j-i));
		while(i<=n && a[j]-a[i-1]>m) ++i;
	}
	cout<<"\n$"<<dfs;*/
