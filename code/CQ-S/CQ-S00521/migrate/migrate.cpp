#include <bits/stdc++.h>
using namespace std;
namespace yhy{
	#define int long long
	const int MAXN=2e6+5;
	const int INF=1e18;
	int n,d;
	int a[MAXN+5];
	int ans=0;
	int lst[MAXN+5],nxt[MAXN+5];
	int cnt_lst[MAXN+5],cnt_nxt[MAXN+5];
	int l_lst[MAXN+5],r_lst[MAXN+5],l_nxt[MAXN+5],r_nxt[MAXN+5];
	int sum[2][MAXN+5];
	int dis[MAXN+5],f[MAXN+5];
	inline void Solve(int l,int r) {

		lst[l]=l;
		for(int i=l+1;i<=r;i++) {
			lst[i]=lst[i-1];
			while(a[i]-a[lst[i]]>d) lst[i]++;
			cnt_lst[lst[i]]++;
			if(!l_lst[lst[i]]) l_lst[i]=i;
			r_lst[lst[i]]=i;
		}
		// cout<<"Pass0\n";		
		nxt[r]=r;
		for(int i=r-1;i>=l;i--) {
			nxt[i]=nxt[i+1];
			while(a[nxt[i]]-a[i]>d) nxt[i]--;
			cnt_nxt[nxt[i]]++;
			if(!r_nxt[nxt[i]]) r_nxt[nxt[i]]=i;
			l_nxt[nxt[i]]=i;
		}
		// cout<<"Pass1\n";

		for(int i=l;i<=r;i++) {
			for(int j=l;j<=r;j++) { dis[j]=INF; f[j]=0; }
			dis[i]=0; f[i]=1;
			for(int j=l;j<=r;j++) {
				for(int k=j+1;k<=nxt[j];k++) {
					if(dis[j]+1>dis[k]) continue;
					if(dis[j]+1==dis[k]) f[k]+=f[j];
					else f[k]=f[j];
					dis[k]=dis[j]+1;
				}
			}
			for(int j=l;j<=r;j++) { if(f[j]==2) ans++; }
		}

		for(int i=l;i<=r;i++) {
			lst[i]=nxt[i]=0;
			cnt_lst[i]=cnt_nxt[i]=0;
			l_lst[i]=r_lst[i]=l_nxt[i]=r_nxt[i]=0;
			sum[0][i]=sum[1][i]=0;
			dis[i]=f[i]=0;
		}
	}
	int main() {
		int opt,T; cin>>opt>>T;
		while(T--) {
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int x=1;x<=n;x++) {
				int y=x;
				while(y<n && a[y+1]-a[y]<=d) y++;
				Solve(x,y);
				x=y;
			}
			cout<<ans<<'\n';
		}

		return 0;
	}
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	yhy::main();
	return 0;
}
/*
爽爽敲键盘干坏事真的爽
15:06 T3
还是警钟长鸣一下子
去年就是半个小时还是一个小时 180 pts 然后坐牢一整场
我怎么感觉我把这个题给秒了
哦还没完，还没处理好前面的点压根不跳到这个点对来的情况
哦不对 i 的前驱的后继不一定是 i 欸这个重要吗
哦是不是只需要验一下当前 l,r 是不是合法的
记得分段处理
哦感觉大概会了
计算一步就能到 i 的且 i+1 一步到不了的
然后每次只走最左边那个点
哦我感觉是互为前驱后继然后再挂一段东西的形式
那应该是真的会了
欸我操刚开始和最后的情况还可以不选最优
怎么错完了
生气了
*/