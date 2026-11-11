#include<bits/stdc++.h>
using namespace std;
//#define int long long
//const int mod=;

long long read() {
	long long x=0;
	int f=1,a=getchar();
	while (a<'0'||a>'9') {
		if (a=='-') f=-1;
		a=getchar();
	}
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x*f;
}

int n;
long long d;
long long x[2000006];

void solve1() {
	scanf("%d",&n);
	d=read();
	for (int i=1; i<=n; i++) x[i]=read();
	if (n==1) {
		printf("0\n");
		return;
	}
	long long g=d/(x[2]-x[1]);
	if (g==0||g==1) {
		printf("0\n");
		return;
	}
	printf("%lld\n",max(0ll,n-(g*2-1)));
	return;
}

int f[20][20][2];

void dfs(int st,int y,int s) {
	if (f[st][y][0]>s) f[st][y][0]=s,f[st][y][1]=0;
	if (f[st][y][0]==s) f[st][y][1]++;
	for (int i=y+1; i<=n; i++) {
		if (x[i]-x[y]<=d) dfs(st,i,s+1);
		else break;
	}
}

void solve2() {
	scanf("%d",&n);
	d=read();
	for (int i=1; i<=n; i++) x[i]=read();
	for (int i=1; i<=n; i++)
		for (int k=1; k<=n; k++)
			f[i][k][0]=f[i][k][1]=1e9;
	for (int i=1; i<n; i++) dfs(i,i,0);
	int ans=0;
	for (int i=1; i<=n; i++)
		for (int k=i+1; k<=n; k++)
			if (f[i][k][1]==2) ans++;
	printf("%d\n",ans);
}

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if (c==11||c==12) while (t--)solve1();
	if (c==1||c==2) while (t--)solve2();

	return 0;
}

