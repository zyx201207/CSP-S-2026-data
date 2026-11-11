#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,sum,l,r,ans,mid;
ll a[500005],And[500005],Le[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	r=n-1;
	for(int i=0;i<n;i++){ 
		cin>>a[i];
	}
	sort(a,a+n);
	for(ll i=1;i<n;i++){
		Le[i]=a[i]-a[i-1];
	}
 	for(ll i=0;i<n;i++){
		if(n-i<=ans) break;
		ll cc=1,aa=0;
		for(int j=i;j<n;j++){
			if(aa+Le[j]*cc>m) break;
			ans=max(ans,cc);
			aa+=Le[j]*cc;
			cc++;
		}
	}
	cout<<ans+1<<'\n';
	
	return 0;
}
//我常常追忆过去
//来不及写游记了，因为跑去写琵琶行了，不过总结，虽然不难，但是题目变化很大
//我觉得T2疑似是缩点之类的，但是我忘记了我缩点怎么学的了
//T3应该是DP，好消息，我不会DP，所以尝试转化为最段路去求，很明显，时间复杂和码量都不小
//T4？这个我看不明白，我觉得应该是和二分图或者和剖分有关，但我不觉得S组考剖分，所以我只学了个剖分求LCA
//而且T4也不一定和剖分有关，反正我的水平太菜了，完全看不懂
//至于T1，我刚开始二分答案，可行，但是没有测试大数据，回来一测试发现错误，然后改用正常的n2写法了，我实在不会了，我觉得T1应该是优化
//还有T2为个人写法是将地铁线缩成点，结果发现有些东西不好搞，就没有搞了，所以大概也就能蒙对几个测试点
//T3我是想到的DP，但是我不会设计状态转移，很明显，通过数学计算得到A特殊点的公式，所以也不知道怎么办
