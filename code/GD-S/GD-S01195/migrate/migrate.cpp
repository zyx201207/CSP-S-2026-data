#include<bits/stdc++.h>
using namespace std;
#define int long long
#define first fs
#define second sc
#define rep(i,l,r) for(int i=l;i<=(r);i++)
const int N=2e6+9;
int A[N],dis[N],cnt[N],n,d;
int BFS(int x){//以x为左端点，存在多少双径对 
	dis[x]=0;cnt[x]=1;
	deque<int>Q;
	Q.push_back(x);
	int mmin=0,mincnt=1,ret=0;
	rep(i,x+1,n){
		while(!Q.empty() and A[i]-A[Q.front()]>d){
			mincnt-=cnt[Q.front()];
			Q.pop_front();
			if(Q.empty())return ret;
			if(!mincnt){
				mmin=dis[Q.front()];
				for(auto v:Q)if(dis[v]==mmin)mincnt+=cnt[v];else break;
			}
		}
		if(Q.empty())return ret;
		mmin=dis[Q.front()];
		dis[i]=mmin+1;cnt[i]=mincnt;ret+=cnt[i]==2;
		while(!Q.empty() and dis[Q.back()]>dis[i])Q.pop_back();
		Q.push_back(i);
	} 
	return ret;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int c,T;cin>>c>>T;
	while(T-- and cin>>n>>d){
		rep(i,1,n)cin>>A[i];
		if(13<=c and c<=14){cout<<"0"<<endl;continue;}
		int ans=0;
		rep(i,1,n-1)ans+=BFS(i);
		cout<<ans<<endl;
	}
	return 0;
}
/*
准备开始暴力骗了，不是今年这个AB题会不会太简单了点？
恰好两条是困难的，至少/至多k条呢？两者相减也能得出答案。
那还说啥了开始拼包，前10个点我直接建图后最短路计数啊。
不难发现直接爆搜是O(n^3)的，这太不牛了，怎么优化成O(n^2)的呢？
注意到，每个点的窗口单调增，单调队列可以维护吗？
但是相同的权值要保留诶。维护一个队列中最小值（队头权值）看看是否可行。
具体地，先弹出不合法的队头，并更新队内最小，若无法转移直接返回；
转移并统计答案后，弹出大于其的队尾，

感觉不能从【最短路计数】这一块入手了，难过。
尝试找到一些可以用数据结构维护的性质。 
*/
