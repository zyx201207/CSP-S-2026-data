#include <bits/stdc++.h>
using namespace std;
#define gc() getchar()
using ll=long long;
const int maxn=5e5+5;
ll read(){
	ll x=0;
	int f=1,ch=gc();
	while (!isdigit(ch)) {
		f=(ch=='-'?-1:f);
		ch=gc();
	}
	while (isdigit(ch)){
		x=x*10+ch-'0';
		ch=gc();
	}
	return x*f;
}
ll a[maxn];
ll d[maxn];
ll pre[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read();
	ll m=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	for (int i=1;i<=n;i++) {
		pre[i]=pre[i-1]+d[i];
	}
	int ans=1,i=1,j=1; 
	ll sum=0;
	while (i<=j&&j<=n){
		while (j<=n){
			j++;
			sum+=(j-i)*d[j];
			if (sum>m) break;
			ans=max(ans,j-i+1);
		}
		while (i<=j) {
			sum-=pre[j]-pre[i];
			i++;
			if (sum<=m) break;
		}
	}
	cout << ans;
	return 0;
} 
