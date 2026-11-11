#include<bits/stdc++.h>
#define int long long
#define pir pair<int,int>
using namespace std;
typedef long long ll;
const int N=2e6+5,M=5005;

inline ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int n,c,t,d,a[N],R[N],cnt[N];

void work2() {
	if(R[1]<3) {
		puts("0");
		return;
	}
	
	printf("%lld\n",max(0ll,n-R[1]-(R[1]-3)));
}

namespace sub3 {
	int dp[M],vv[M],du[M],tmp[M];
	vector<int> kk[M];
	void slove() {
		for(int i=1;i<=n;i++) kk[i].clear(),du[i]=0;
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(a[j]-a[i]<=d) kk[i].push_back(j),du[j]++;
				else break;
			}
		}
		
		
		int ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) dp[j]=0,vv[j]=0x3f3f3f3f3f3f3f3f,tmp[j]=du[j];
			dp[i]=1,vv[i]=0;
			queue<int> q;
			q.push(i);
			while(q.size()) {
				int x=q.front();
				q.pop();
				for(int y:kk[x]) {
					if(vv[y]>vv[x]+1) {
						vv[y]=vv[x]+1;
						dp[y]=dp[x];
					}
					else if(vv[y]==vv[x]+1) {
						dp[y]+=dp[x];
					}
					
					if(!--tmp[y]) q.push(y);
				}
			}
			for(int j=i+1;j<=n;j++) {
				if(dp[j]==2) ans++;
			}
			for(int y:kk[i]) du[y]--;
		}
		
		printf("%lld\n",ans);
	}
}

void work() {
	int ans=0;
	n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read(),cnt[i]=1;
	
	int r=0;
	for(int i=1;i<=n;i++) {
		while(r<n && a[r+1]-a[i]<=d) r++;
		R[i]=r;
	}
	
	bool flag=1;
	for(int i=3;i<=n;i++) {
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=0;
	}
	if(flag) {
		work2();
		return;	
	}
	
	if(n<=5000) {
		sub3::slove();
		return;
	}
	
	for(int i=1;i<n;i++) {
		int op1=R[i];
		int op2=R[op1-1],op3=R[op1-2];// r[i]-2 ºÍ r[i]-1
		ans+=cnt[i]*(op2-op3);
	}
	printf("%lld\n",ans);
}

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	c=read(),t=read();
	while(t--) work();
	return 0;
}
// Oct31==Dec25?
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
