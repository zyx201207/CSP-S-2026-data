#include <bits/stdc++.h>
using namespace std;
int c,T;
int n;
long long a[2000005],d;
long long re[305][305],num[305][305];
vector<int>s[305];
long long read() {
	long long f=1,k=0;
	char c;
	c=getchar();
	while (c<'0'||c>'9') {
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9') {
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
void dfs(int st,int now,int sp) {
	if (st==now) {
		re[st][st]=1;
		num[st][st]=1;
	}
	else {
		if (re[st][now]>sp) {
			re[st][now]=sp;
			num[st][now]=1;
		}
		else if (re[st][now]==sp) {
			num[st][now]++;
		}
	}
	for (auto i:s[now]) {
		dfs(st,i,sp+1);
	}
}
void solve1() {
	int ans=0;
	for (int cfsz=0;cfsz<T;cfsz++) {
		cin>>n>>d;
		memset(a,0,sizeof(a));
		ans=0;
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=301;i++) s[i].clear();
		int top=1;
		for (int i=1;i<=n;i++) {
			while (a[top]<=d+a[i]&&top<=n) {
				top++;
			}
			for (int j=i+1;j<top;j++) {
				s[i].push_back(j);
			}
		}
		for (int i=1;i<=301;i++) {
			for (int j=1;j<=301;j++) {
				re[i][j]=1000;
				num[i][j]=0;
			}
		}
		for (int i=1;i<=n-3;i++) dfs(i,i,0);
		for (int i=1;i<=n-3;i++) {
			for (int j=i+1;j<=n;j++) ans+=(num[i][j]==2);
		}
		cout<<ans<<'\n';
	}
}
void solve2() {
	for (int cfsz=0;cfsz<T;cfsz++) {
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++) a[i]=read();
		long long l=d/(a[2]-a[1]);
		if (l==1) cout<<0<<'\n';
		else {
			if (n-2*l+1<0) cout<<0<<'\n';
			else cout<<n-2*l+1<<'\n';
		}
	}
	return ;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if (c<=6) solve1();
	else if (c==11||c==12) solve2();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
