#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2005,L=10;
int n,m;
//int b[N];
ll a[N],ma;
ll f[1<<25];//.?十进制答案 
int zh1(ll x) {//10->2
	int res=0;
	while(x) {
		res=res*10+(x&1);
		x>>=1;
	}
	return res;
}
ll zh2(int x) {//10->2
	ll res=0;
	while(x) {
		res=res*10+(x&1);
		x>>=1;
	}
	return res;
}
int q(int x) {//状态选择数的个数 
	int t=0;
	while(x) {
		t+=x&1;
		x>>=1;
	}
	return t;
}
int g(int a,int b) {//按位与 (a:10,b:10->res:10)
	int res=0;
	for(int k=L-1;k>=0;k--) 
		res=res*2+((a>>k)&1)&((b>>k)&1);
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	ll t=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		t=max(t,a[i]);
//		b[i]=zh1(a[i]);
	}
	if(m==1) {cout<<t;return 0;}
	for(int i=1;i<=n;i++) {//两个数的情况 
		for(int j=1;j<=n;j++) {
			if(i==j) continue;
			f[(1<<(i-1))|(1<<(j-1))]=a[i]&a[j];
		}
	}
	//---
	for(int zt=1;zt<(1<<20);zt++) {//枚举状态 
		int len=q(zt);
		if(len>m||len==2) continue;
		for(int k=L-1;k>=0;k--) {
			if((zt>>k)&1) {
				f[zt]=g(f[zt^(1<<k)],a[k]);
			}
		}
		if(len==m) ma=max(ma,f[zt]);
	}
	cout<<ma;
	
	return 0;
}
