#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10, MOD=1e9+7;
int T, n, m, q, k, a[N], b[N], dp[N], cnt, tot, ans, maxn, minn=0x3f3f3f3f;
int read(){
	int s=0, f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0) x=-x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n=read(), m=read();
	bool pd1=1, pd2=1;
	for(int i=1; i<=n; i++){
		a[i]=read();
		if(a[i]!=i) pd1=0;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) pd2=0;
	}
	sort(a+1, a+n+1);
	if(pd1){
		for(int i=1; i<=n; i++){
			if(i*(i+1)/2>m){
				write(i), puts("");
				return 0;
			}
		}
	}
	else if(pd2){
		int d=a[2]-a[1];
		for(int i=1; i<=n; i++){
			if(i*(i+1)*d/2>m){
				write(i), puts("");
				return 0;
			}
		}
	}
	else if(n<=5000){
		for(int i=1; i<=n; i++){
			b[i]=b[i-1]+(a[n]-a[i]);
		}
		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				if((b[j]-j*(a[n]-a[j]))-(b[i]-i*(a[n]-a[j]))+(i*(a[n]-a[j]))<=m) ans=max(ans, j-i+1);
			}
		}
		write(ans), puts("");
	}else{
		for(int i=2; i<=n; i++){
			tot=0;
			for(int j=i; j>=1; j--){
				tot+=a[i]-a[j];
				if(tot>m){ans=max(ans, i-j);break;}
			}
			if(tot<=m) ans=max(ans, i);
		}
		write(ans), puts("");
	}
	return 0;
}
