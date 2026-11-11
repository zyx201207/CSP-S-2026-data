#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5*1e5+3;

int read() {
	int x=0,f=1,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

clock_t start=clock();
int n,m,ans=0;
int a[N],f[N];

void solve1() {
	ans++;
	for(int i=1;i<=n-1;i++) {
		if(m>=i) {
			m-=i;
			ans++;
		}
		else break;
	}
	cout<<ans;
}

void solve2() {
	ans++;
	int delta=a[2]-a[1];
	for(int i=1;i<=n-1;i++) {
		if(m>=i*delta) {
			m-=delta;
			ans++;
		}
		else break;
	}
	cout<<ans;
}

void solve3() {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(a[i]<a[j]) f[j]=0x3f3f3f3f3f3f3f3f;
			else f[j]=a[i]-a[j];
		}
		sort(f+1,f+1+n);
		int res=0,mm=m;
		for(int j=1;j<=n;j++) {
			if(mm>=f[j]) {
				mm-=f[j];
				res++;
			}
			else break;
		}
		ans=max(ans,res);
		if((double)(clock()-start)/CLOCKS_PER_SEC>0.97) {
			cout<<ans;
			return;
		}
	}
	cout<<ans;
}

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	bool f1=1,f2=1;
	n=read(),m=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();
		if(a[i]!=i) {
			f1=0;
		}
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f2=0;
	}
	if(f1) {
		solve1();
		return 0;
	}
	if(f2) {
		solve2();
		return 0;
	}
	solve3();
}
