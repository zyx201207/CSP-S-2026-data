#include<bits/stdc++.h>
//#define long long long long
//#define ulong long unsigned long long
using namespace std;
const int maxn=5e5+10;
long long m,a[maxn];
int n,ans;
long long qian[maxn];
inline int readint(){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline long long readll(){
	long long x=0;
	int f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*(long long)f;
}
inline bool check(int k){
	for(int i=1;i+k-1<=n;i++){
		int j=i+k-1;
		if(((long long)k*a[j]-(qian[j]-qian[i-1]))<=m)return 1;
	}
	return 0;
}
//long long read(){
//	long long x=0,f=1;
//	char c=getchar();
//	while(c>'9'||c<'0'){
//		if(c=='-')f=-1;
//		c=getchar();
//	}
//	while(c<='9'&&c>='0'){
//		x=x<<1+x<<3+c-'0';
//		c=getchar();
//	}
//	return x*f;
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	n=readint();
	m=readll();
	for(int i=1;i<=n;i++){a[i]=readll();}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){qian[i]=qian[i-1]+a[i];}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}

