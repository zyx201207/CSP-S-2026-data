#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n,d,x[N],f[N],a[N],dp[N],b[N][2];
int dfs(int r) {
	int l=r-1;
	if(dp[r])return dp[r];
	if(f[l]==f[r]) {
		return 0;
	} else {
		dp[r]=f[r]-f[l]+dfs(f[r]);
		return dp[r];
	}
}
int bfs(int x,int r) {
	if(x<=r)return 0;
	if(b[x][min(1ll,x-r-1)])return b[x][min(1ll,x-r-1)];
	if(x-r-1==0) {
		b[x][0]=bfs(f[x],f[r]);
		return b[x][0];
	} else {
		int l=x-2;
		r=l+1;
		if(f[x]!=f[r]) {
			b[x][1]=bfs(f[x],f[r])+f[r]-f[l];
			return b[x][1];
		} else {
			if(f[r]-f[l]!=0&&f[f[r]-1]!=f[f[r]]) {
				return f[r]-f[l]+dfs(f[r]);
			} else {
				return f[r]-f[l];
			}
		}
	}
}
int solve(int x) {
	if(f[x]==x)return 0;
	int l=x,r=x;
	l=f[x]-2;
	r=f[x]-1;
	if(f[f[x]]!=f[r]) {
		return bfs(f[f[x]],f[r])+f[r]-f[l];
	} else {
		if(f[r]-f[l]!=0&&f[f[r]-1]!=f[f[r]]) {
			return f[r]-f[l]+dfs(f[r]);
		} else {
			return f[r]-f[l];
		}
	}
}

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T>>T;
	while(T--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
			b[i][0]=b[i][1]=dp[i]=0;
		}
		int r=1;
		for(int i=1; i<=n; i++) {
			while(r<n&&x[r+1]-x[i]<=d) {
				r++;
			}
			f[i]=r;
		}
		int ans=0;
		r=n;
		for(int i=n; i>=1; i--) {
			if(f[i]-i==0) {
				r=i;
				a[i]=r;
				continue;
			} else if(f[i]-i==1) {
				ans+=solve(r);
			} else {
				ans+=solve(i);
				r=i;
			}
			a[i]=r;
		}
		cout<<ans<<"\n";
	}
}
/*
1 1
12 3
1 2 3 4 5 6 7 10 11 12 14 15



1 1
10 3
1 2 3 4 5 6 8 9 10 12




*/

/*
1 1
10 333333333333333327
-1000000000000000000 -666666666666666673
-333333333333333346 -111111111111111128
111111111111111090 222222222222222199
333333333333333308 444444444444444417
666666666666666635 999999999999999962
1 1
10 7
1 7 14 21 24 25 29 30 33 40

0 0 0 0 2 2 2 2 2 2 2
12



16


*/


/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
性质1：对于每个点，只要考虑他能走到的最远的3个点即可，不会回头
同时第三个点先走到的点不可做为答案
对于n<5000,跑spfa即可，每个点只建3条边O(n*n*3/2),剩下的交给少爷机
40pts
A；即每个点可以走到的点为i+x，i+x+1，i+x+2
设每个点能走到的点数为k
k=1
输出0
k=3
能走两步（一步是i+x+1）的点贡献1，else 0
 k=2
 能走三步的贡献
 48pts
  每个点对答案的贡献为1段区间
	发现"正解"代码极短，决定验证
NO

oh 完蛋 
*/
