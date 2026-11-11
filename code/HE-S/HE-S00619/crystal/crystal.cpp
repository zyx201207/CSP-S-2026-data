#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500001];
int vis[200005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]+=100000;
	}
	int minn=LLONG_MAX;
	int maxn=LLONG_MIN;
	int Dow;
	for(int i=0;i<m;i++){//m次操作 
		for(int j=0;j<200001;j++){
			vis[j]=0;
		}
		for(int j=0;j<n;j++){//找出最少的 
			if(a[j]<minn){
				minn=a[j];
				Dow=j;
			}
		}
		a[Dow]++;//最少的++ 
		for(int j=0;j<n;j++){
			vis[a[j]]++;
		}
		for(int j=0;j<=200001;j++){
			if(vis[j]!=LLONG_MIN){
				maxn=max(maxn,vis[j]);
			}
		}
	}
	cout<<maxn+1;
	return 0;
}
/*
15:02
初二蒟蒟蒟蒟蒟蒟蒟蒟蒟蒟蒟蒟蒟蒟蒻 
非常好题目 使我的大脑旋转 爱来自CCF
我是FW 
15:10
平静的后厨培养不出哈气的基米 
苏维埃正红旗 带你体验红色泥头车 
15:16
写了个暴力
	#include<bits/stdc++.h>
	#define int long long
	using namespace std;
	int a[500001];
	int vis[200001];
	signed main(){
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		//freopen("crystal.in","r",stdin);
		//freopen("crystal.out","w",stdout);
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]+=100000;
		}
		int minn=LLONG_MAX;
		int maxn=LLONG_MIN;
		int Dow;
		for(int i=0;i<m;i++){//m次操作 
			for(int j=0;j<200001;j++){
				vis[j]=0;
			}
			for(int j=0;j<n;j++){//找出最少的 
				if(a[j]<minn){
					minn=a[j];
					Dow=j;
				}
			}
			a[Dow]++;//最少的++ 
			for(int j=0;j<n;j++){
				vis[a[j]]++;
			}
			for(int j=0;j<=200001;j++){
				if(vis[j]!=LLONG_MIN){
					maxn=max(maxn,vis[j]);
				}
			}
		}
		cout<<maxn+1;
		return 0;
	}
桶太好用了你们知道吗 
就是为啥每次都少1呢，不敢说正确 
面向结果编程这一块 
15:23
至少应该有分了，不会爆零罢 
15:34
这太难了
虽然是第一次S组
但被第一题创飞也太糟糕了
15:42
赛前一直在颓
要期中了，浮木和老师还都要求whk成绩 
OI基本没练啊浮木还说S不拿1=就要半AFO了(?
真的假的这是我能做到的吗有2=都算菩萨保佑了 
更何况去优先复习J了 
现在看毫无悬念了
威化好吃。
嚼嚼嚼。 
上午考J组居然不让带吃的
饿死我了
嚼嚼嚼 。 
我怎么看不懂后面题。
15:48
哦看懂了 
但是不会。 
我该如何在还有18天期中，年级有2000多人的情况下进入年级前一百
279工程是辆好车。 
嚼嚼嚼。 
阿巴阿巴
我咋感觉我图论跟没学一样
啥也想不起来
15:53
算了还是去想T1正解吧
我咋这么废。 
哇左边的人怎么做T3了
吓哭了
15:57
万恶的TCTM
卷钱跑路搞得我 DP及以前完全依托 
虽然后面也学的不咋样吧
嚼嚼嚼。 
16:02
坐牢
去个厕所 
16:10
回来了
咋不知不觉写这么多了
有点浪费时间。
再看看题吧 
16:12
"他可以进行'至多' m 次操作 "
也就是说不一定执行m次
好像没啥用
maxn取的就是同样的数最多的时候(如果我想法没错的话)
相当于操作到这一步就停
滚木滚木滚木。
我咋感觉我想的是错的。 
16:19
10^18 10^12吓哭了
何数据范围
今年HE有人做迷惑行为大赏吗
关注Enzo_Kevin谢谢喵 
*/ 

