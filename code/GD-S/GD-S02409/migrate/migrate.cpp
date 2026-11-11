/*
首先易得暴力做法。O(n^2)。预计 10 分钟。
边连的是一个区间，可能要有什么优化在上面。

看看特殊性质，等差数列时，每个点的连边区间相同。此时越往右越优。
求出 i 最多能往右多少步，记作 k，好像只有 i+2k-1 这个点可能有贡献。的确。
预计 5 分钟。

第二个特殊性质。因为边是双向的，所以 dis 恒为 2。更特殊的，这意味这 x[n]<=2d。
所以需要找出，对于 u 来说，走两步能唯一到达的点有多少个。
实际上可以将最短路计数理解为区间 +1,每一次只有最外层的可以活下来。
所以需要找到区间的 次小/大值 和 次次小/大值，那一段是可行的点。这个是可以单调队列处理的。
注意到区间的 l 是递减的，这是个很美丽的性质。
意味着次小值一定由区间第二小产生，次次小由区间第三小产生。
预计 10 分钟。

第三个特殊性质。意味着最短路最多为 10。
仔细观察，发现，每走一步，最多只有三个点是有用的。只有最外面的 3 个点有用。
其中，[1,2] 负责下一步，[2,3] 负责增加贡献。
由于最多扩展 10 次，我们可以写出一个模拟算法：
给出一个区间，取最左边三个点，然后根据 [2,3] 算贡献（左闭右开），[1,2] 成为下一个区间。
时间复杂度 O(10n)。

感觉有点难写，还有好多边界情况，估计要写一个小时。先跳过吧。
*/
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

using ll = long long ;
using ii = __int128;
using vl = vector<ll>;
using vi = vector<int>;
using a2 = array<int,2>;
using va = vector<a2>;

const int inf=1e9;

vi cal(int n,ll d,vl &x)
{
	vi a(n+5);
	for(int i=1,r=1;i<=n;i++)
	{
		while(r<=n&&x[r]-x[i]<=d) r++;
		a[i]=r-1;
	}
	return a;
}

void s1()
{
	int n; ll d; cin>>n>>d;
	vl x(n+5);
	for(int i=1;i<=n;i++) cin>>x[i];
	vi nxt=cal(n,d,x);

	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		queue<int> q; q.push(i);
		vi dis(n+5,inf),cnt(n+5); dis[i]=0; cnt[i]=1;
		while(q.size())
		{
			int u=q.front(); q.pop();
			for(int v=u;v<=nxt[u];v++)
			{
				if(dis[v]<dis[u]+1) continue ;
				else if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
				else
				{
					cnt[v]=cnt[u];
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
		for(int j=i;j<=n;j++) if(cnt[j]==2) ans++;
	}
	cout<<ans<<"\n";
}

void s2()
{
	int n; ll d; cin>>n>>d;
	vl x(n+5);
	for(int i=1;i<=n;i++) cin>>x[i];
	vi nxt=cal(n,d,x);

	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int k=nxt[i]-i;
		if(i+2*k<=n) ans++;
	}
	cout<<ans<<"\n";
}

void s3()
{
	int n; ll d; cin>>n>>d;
	vl x(n+5);
	for(int i=1;i<=n;i++) cin>>x[i];
	vi nxt=cal(n,d,x);

	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int ok=nxt[i]-i;
		if(ok<=1) continue ;
		int r=nxt[nxt[i]-1];
		if(ok==2)
		{
			ans+=r-nxt[i];
		}
		int l=nxt[nxt[i]-2];
		ans+=r-l;
	}
	cout<<ans<<"\n";
}

int main()
{
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,T; cin>>c>>T;
	while(T--)
	{
		if(c<=10) s1();
		else if(c<=12) s2();
		else if(c<=14) s3();
		else s1();
	}
}
// g++ migrate.cpp -o migrate -std=c++14 -Wall -Wextra -O2 -Wshadow && .\migrate && fc migrate.out migrate.ans
