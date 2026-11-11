#include<bits/stdc++.h>
#define ll long long
const int N = 2e5+10;
using namespace std;
template <typename T>
inline bool read(T &sum){
	int c = sum = 0;
	while(c<'0'||c>'9')if(c==EOF)return 0;else c=getchar();
	while(c>='0'&&c<='9')sum=(sum<<1)+(sum<<3)+c-'0',c=getchar();
	return 1;
}
ll lmax(ll a, ll b){
	return a>b?a:b;
}
ll n,m,a[N], ded = -1;
inline void dfs(int f, int s, int num){
	if(f+s > n) return ;
	if(s <= 1) return void(ded = lmax(ded,num));
	for(int i = f+1; i <= n-s+1; i++)
		dfs(i,s-1,a[i]&num);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	read(n);read(m);
	if(m==1){
		ll ded = 0;
		for(int i=1;i<=n;i++)read(a[i]),ded=lmax(ded,a[i]);
		return cout << ded,0;
	}else if(m==n){
		ll ded = 0;
		for(int i=1;i<=n;i++)read(a[i]),ded=ded&a[i];
		return cout << ded,0;
	}else if(m == 2){
		ll ded = 0,ede = 0;
		for(int i=1;i<=n;i++)read(a[i]),ded=lmax(ded,a[i]);
		for(int i=1;i<=n;i++)ede=lmax(ede,ded&a[i]);
		return cout << ede,0;
	}else if(m == 3){
		ll ded = 0,ede = 0,ses;
		for(int i=1;i<=n;i++)read(a[i]),ded=lmax(ded,a[i]);
		for(int i=1;i<=n;i++)ede=lmax(ede,ded&a[i]);
		for(int i=1;i<=n;i++)ses=lmax(ede,ded&a[i]);
		return cout << ses,0;
	}
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n-m+1; i++) dfs(i,m,a[i]);
	cout << ded;
	return 0;
}
