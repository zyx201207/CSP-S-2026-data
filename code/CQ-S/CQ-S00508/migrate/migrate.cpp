#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,c,d,su[N],t,cnt[N],f[N],ans,cnt2[N];
deque<int> q;
inline void solve1(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cnt[j]=0,cnt2[j]=0;
		while(!q.empty())q.pop_back();
		f[i]=0,cnt[i]=1,cnt2[0]=1;q.push_back(i);
		for(int j=i+1;j<=n;j++){
			while(!q.empty()&&su[q.front()]<su[j]-d)
				cnt2[f[q.front()]]-=cnt[q.front()],q.pop_front();
			if(q.empty())break;
			int wer=q.front();
			f[j]=f[wer]+1,cnt[j]+=cnt2[f[wer]],cnt2[f[j]]+=cnt[j];
			while(!q.empty()&&f[q.back()]>f[j])cnt2[f[q.back()]]-=cnt[q.back()],q.pop_back(); 
			q.push_back(j);if(cnt[j]==2)ans++;
		//	cout<<i<<" "<<j<<" "<<cnt[j]<<endl;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>su[i];
		if(n<=5000)solve1();
	}
	return 0;
}
/*
严肃开写t3
先看部分分，尝试把n<=5000的数据给写了
嗯，好像可以单调队列优化DP加上暴力枚举左端点
能够获得40pts的好成绩
尝试获得更高分数
A性质这个看起来挺幽默的
显然如果公差大于d的一半，答案为零 
否则的话应该是有规律可循的
对于第一个位置为左端点暴力DP然后后面的贡献都是一样的除非还没有超出两条路径就走到头了
可以获得48pts的好成绩
先写吧 
算了看看能不能再找点性质 ？ 
我以为还是先打暴力为妙 
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
已获得 40pts 
先看t4 
*/
