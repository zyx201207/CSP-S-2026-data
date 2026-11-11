#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
inline int read(){
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int x=0;
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
inline ll readll(){
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	ll x=0;int f=(ch=='-'?ch=getchar(),-1:1);
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
void put(int x){
	if(x>9) put(x/10);
	putchar((x%10)^48);
}
void putll(ll x){
	if(x>9) put(x/10);
	putchar((x%10)^48);
}
int n;
ll m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=readll();
	for(int i=1;i<=n;i++) a[i]=readll();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int res=0;
	for(int i=1,j=0;i<=n;i++){
		while(j<i&&a[i]*(i-j)-(sum[i]-sum[j])>m) j++; 
		res=max(res,i-j);
	}
	put(res);
	return 0;
}
/*
5 80000000000000000
-30000000000000000 -10000000000000000 20000000000000000 20000000000000000 70000000000000000
*/
