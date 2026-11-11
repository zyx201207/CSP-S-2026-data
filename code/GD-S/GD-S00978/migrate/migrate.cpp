#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+6;
int c , t;
int n , x[N] , d , dp[N];
int q[N] , fa[N] , ans;
struct s{
	int st , ed , cnt;
}f[N];
void mush(int start)
{
	for(int i=1;i<=n+100;i++)q[i]=0,f[i]={},fa[i]=0;
	for(int i=start+1;i<=n;i++)
		dp[i]=0;
	if(start==n)
		return ;
	dp[start]=0;
	int st=1,ed=1;
	f[st].st = f[st].ed = 0 , f[st].cnt=1;
	fa[start]=1;q[f[st].st]=start;
	//d[i]-d[j]<=d
	for(int i=start+1;i<=n;i++)
	{
		while(st<=ed&&x[i]-x[q[f[st].st]]>d){
			while(x[i]-x[q[f[st].st]]>d&&f[st].st<=f[st].ed)
				f[st].cnt-=fa[f[st].st],f[st].st++;
			if(f[st].st>f[st].ed)st++;
		}
		dp[i]=dp[q[f[st].st]]+1,fa[i]=f[st].cnt;
		//if(fa[i]>2)continue; 
		//cout<<dp[i]<<" "<<fa[i]<<" "<<f[st].st<<" "<<st<<' '<<dp[q[f[st].st]]<<'\n';
		//cout<<dp[i]<<' '<<dp[q[f[ed].ed]]<<' '<<q[f[ed].ed]<<'\n';
		while(st<=ed&&dp[q[f[ed].ed]]>dp[i])
			ed--;
		if(ed<st||dp[q[f[ed].ed]]<dp[i]){
			if(ed<st){
				//cout<<"case1";
				st=ed=0;
				f[ed].st=f[ed].ed=0;
			}else
			{
				///cout<<"case2 "<<ed<<'\n';
				ed++;
				f[ed].st=f[ed].ed=(f[ed-1].ed+1);
			}
			q[f[ed].ed]=i,f[ed].cnt=fa[i];
			continue ;
		}
		//cout<<dp[i]<<' '<<dp[q[f[ed].ed]]<<' '<<q[f[ed].ed]<<'\n';
		if(dp[q[f[ed].ed]]==dp[i])
		{	
			f[ed].ed++;
			q[f[ed].ed]=i;
			f[ed].cnt+=fa[i];
			//cout<<"add"<<ed<<' '<<f[ed].cnt<<' '<<fa[i]<<'\n';
		}

	}
	for(int i=start+1;i<=n;i++){
		//cout << start<<' '<<i<<' '<<fa[i]<<'\n'; 
		if(fa[i]==2)
			ans++;
	}
	//cout << "\n\n\n";
	return ;
}
void solve()
{
	ans=0;
	cin >> n >> d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	if(n==1)
	{
		cout<<0<<'\n';
		return ;
	}
	//[st , ed]
	//记住存储的是下标，别调试1万年
	//初始为空
	/*
	如果队首到不了弹出：st++;
	加入时：如果队尾次数更大则弹出，等于的话方案数要加起来，
	这个因为需要维护哪些是方案数相同的，需要单调队列里面套单调队列
	建议用时20min之内，但是不要打太快了，心急则难调
	具体考虑一下要维护什么信息：不用每个内部再单独开一个队列，全部堆在一起。
	记录:
	st,ed在q的s开始，e结束，同时还要记录方案数，次数查询dp值即可
	还要每次清空
	*/
	for(int i=1;i<n;i++)
		mush(i);
	cout << ans << '\n';

	return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 13 16 19
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

*/
