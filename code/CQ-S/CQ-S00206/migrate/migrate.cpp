#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
long long d,a[2000020],b[2000020],f[2000020],qzh[2000020],pos[2000020],bs[2000020],ans;
int get(int l,int r,long long w){
	int res=upper_bound(qzh+l,qzh+r+1,w)-qzh-1-l+1;
	return res;
}
void solve(){
	for(int j=1;j<=m;j++)pos[j]=0;
	for(int j=1;j<=m;j++)qzh[j]=qzh[j-1]+b[j];
	for(int j=1;j<=m;j++){
		pos[0]=j-1;
		int len=0,tot=0;
		while(1){
			len++;
			pos[len]=max(pos[len],pos[len-1]+1);
			while(pos[len]<m&&qzh[pos[len]+1]-qzh[pos[len-1]]<=d)pos[len]++;
			if(pos[len]==m)break;
		}
//			////cerr<<"round block "<<j<<' '<<len<<'\n';
//			for(int i=1;i<=len;i++)////cerr<<pos[i]<<' ';
		////cerr<<'\n';
		for(int i=2;i<=len;i++){
			//cerr<<"j i tot ans pos"<<j<<' '<<i<<' '<<tot<<' '<<ans<<' '<<pos[i]<<'\n';
			if(tot==0){
				// 此处最新需要有 1 次命中
				// 满足：nowsum + prev[end] <= d 并且 nowsum + prev[end] + prev[end-1] > d 
				// 并且左移之后，前一个不可以有办法再左移
				if(i==2||(qzh[pos[i-1]-1]-qzh[pos[i-2]]+b[pos[i-2]]>d)){
					if(pos[i-1]==pos[i-2]+1){
						// nowsum <= d - prev[end]
						// qzh[j] - qzh[pos[i-1] <= d - prev[end]
						// qzh[j] <= d + qzh[pos[i-1] - prev[end]
						long long w=qzh[pos[i-1]] + d - b[pos[i-1]];
						//cerr<<"j i A w"<<j<<' '<<i<<' '<<w<<'\n';
						ans+=get(pos[i-1]+1,pos[i],w);
					}
					else{
						// qzh[j] - qzh[pos[i-1] + prev[end] + prev[end-1] > d 
						// qzh[j] > d + qzh[pos[i-1] - prev[end-1] - prev[end]
						long long w=qzh[pos[i-1]] + d - b[pos[i-1]];
						ans+=get(pos[i-1]+1,pos[i],w);
						//cerr<<"j i B w"<<j<<' '<<i<<' '<<w<<'\n';
						w=qzh[pos[i-1]] + d - b[pos[i-1]] - b[pos[i-1]-1];		
						//cerr<<"j i C w"<<j<<' '<<i<<' '<<w<<'\n';				
						ans-=get(pos[i-1]+1,pos[i],w);
					}
				}
			}
			else if(tot==1){
				// 此处任何都不能命中 
				// 满足：nowsum + prev[end] > d 
				// qzh[j] > d + qzh[pos[i-1] - prev[end]
				long long w=qzh[pos[i-1]] + d - b[pos[i-1]];
				//cerr<<"j i D w"<<j<<' '<<i<<' '<<w<<'\n';
				ans+=(pos[i]-pos[i-1]-get(pos[i-1]+1,pos[i],w));
			}
			else break;
			long long nowsum=qzh[pos[i]]-qzh[pos[i-1]];
			if(nowsum+b[pos[i-1]]<=d){
				tot++;
				if(i>=3&&qzh[pos[i-1]-1]-qzh[pos[i-2]]+b[pos[i-2]]<=d){
					tot++;
				}
			}
			if(pos[i-1]!=pos[i-2]+1){
				if(nowsum+b[pos[i-1]]+b[pos[i-1]-1]<=d)tot++;
			}
		}
	}
	m=0;
}
void solve2(){
	int tot=0,bc=0;
	long long sum=0;
	pos[0]=0;
	for(int i=1;i<=m;i++){
		if(b[i]+sum>d){
			pos[++bc]=i-1;
			bs[bc]=sum;
			sum=0;
		}
		else{
			if(bc>=1){
				if(sum+b[pos[bc]]<=d){
					tot--;
					if(bc>=2&&bs[bc]-b[pos[bc]]+b[pos[bc-1]]<=d)tot--;
				}
				if(pos[bc]!=pos[bc-1]+1&&sum+b[pos[bc]]+b[pos[bc]-1]<=d)tot--;
			}
		}
		sum+=b[i];
		if(bc>=1){
			if(sum+b[pos[bc]]<=d){
				tot++;
				if(bc>=2&&bs[bc]-b[pos[bc]]+b[pos[bc-1]]<=d)tot++;
			}
			if(pos[bc]!=pos[bc-1]+1&&sum+b[pos[bc]]+b[pos[bc]-1]<=d)tot++;
		}
//		cerr<<i<<' '<<tot<<'\n';
		if(tot==1){
			ans+=(m-i+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		if(c==11||c==12){
			m=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(n>1&&a[2]-a[1]<=d){
				m=n-1;
				for(int i=1;i<=m;i++)b[i]=a[2]-a[1];
				solve2();
			}
		}
		else{
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			m=0;
			for(int i=1;i<n;i++){
				if(a[i+1]-a[i]<=d){
					b[++m]=a[i+1]-a[i];
					if(i==n-1)solve();
				}
				else{
					solve();
				}
			}
		}
		cout<<ans<<'\n';
		ans=0;
//		cerr<<clock()<<'\n';
	}
	









	return 0;
}

/*

给一个序列，问有多少个区间，满足存在恰好两个子序列，是“相邻差不超过 k”子序列中最短的

那首先可以定 l 动 r DP 单调队列维护方案数 

事实上求这个最短子序列可以贪心

或者说只考虑差分数组，那么就是区间划分

只存在 2 种区间划分，得到了最优解

那么肯定是在贪心的基础上做一点小调整得到的

例如 k = 2

1 1 1

划分有两种（只记录结束点） 1,3 和 2,3

2,3 是贪心，所有结束点都不能再右移动

因此想要调整一定是左移动

如果存在恰好一个位置左移动成功，就成功

0 个和 2 个都不行

并不会出现有点左移动后，有点就可以右移动了

给每个 endpos 挂两个数：(sum,aend)

当且仅当 prev_aend + sum <= limit 时，合法

动态维护，即可 O(n^2)

但是还要注意，一个位置不可以连续左移两次，也就是说 prev_a[end-1] + prev_aend + sum > limit

等差数列容易统计，判定 1~n-1 个差是否可行，并拆贡献即可

我精细实现一下是不是可以做到 72？

要么是此前有一个，并且现在没有

要么是现在有一个，并且此前没有 



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


0 1
8 3
0 1 2 4 8 10 11 13
should 2

边界 n=1 

10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

0 1
10 3
0 3 6 7 8 9 10 11 14 17
3 3 1 1 1 1 1 3 3

0 1
6 2
1 3 4 5 6 8

2 1 1 1 2

migrate.exe < migrate1.in > migrate1.out
migrate.exe < migrate2.in > migrate2.out
migrate.exe < migrate3.in > migrate3.out
migrate.exe < migrate4.in > migrate4.out
migrate.exe < migrate5.in > migrate5.out
fc migrate1.ans migrate1.out
fc migrate2.ans migrate2.out
fc migrate3.ans migrate3.out
fc migrate4.ans migrate4.out
fc migrate5.ans migrate5.out
migrate.exe < migrate6.in > migrate6.out
fc migrate6.ans migrate6.out

migrate.exe < migrate4.in > migrate4.out
fc migrate4.ans migrate4.out


0 1
11 8
2 4 6 8 10 12 14 16 18 20 22

11 1
11 8
2 4 6 8 10 12 14 16 18 20 22

11 1
10 21
0 7 14 21 28 35 42 49 56 63

D:\CQ-S00206>fc migrate1.ans migrate1.out
正在比较文件 migrate1.ans 和 MIGRATE1.OUT
FC: 找不到差异


D:\CQ-S00206>fc migrate2.ans migrate2.out
正在比较文件 migrate2.ans 和 MIGRATE2.OUT
FC: 找不到差异


D:\CQ-S00206>fc migrate3.ans migrate3.out
正在比较文件 migrate3.ans 和 MIGRATE3.OUT
FC: 找不到差异


D:\CQ-S00206>fc migrate4.ans migrate4.out
正在比较文件 migrate4.ans 和 MIGRATE4.OUT
FC: 找不到差异


D:\CQ-S00206>fc migrate5.ans migrate5.out
正在比较文件 migrate5.ans 和 MIGRATE5.OUT
FC: 找不到差异
D:\CQ-S00206>migrate.exe < migrate6.in > migrate6.out
46
78
93
109
140
140
140
140
140
140
140
140
140
140
140

D:\CQ-S00206>fc migrate6.ans migrate6.out
正在比较文件 migrate6.ans 和 MIGRATE6.OUT
FC: 找不到差异
*/

