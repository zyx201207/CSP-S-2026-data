#include <bits/stdc++.h>
using namespace std;
const int N=500005;
const int M=100005;
int v[N];
int a[505][N];
int rb[M];
int ren[M];
int dp[505];
int c,n,m,d,q;
queue<int> qq;
int atime[505][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int atime[505][N];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++)
		{
			cin>>a[i][j]>>atime[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>rb[i]>>ren[i];
	}
	for(int i=1;i<=q;i++)
	{
		memset(dp,0x3f,sizeof dp);
		qq.push(rb[i]);
		dp[rb[i]]=v[rb[i]];
		while(qq.size())
		{
			for(int j=1;j<=d;j++)
			{
				if(a[j][qq.front()]!=0)
				{
					for(int ij=1;ij<=a[j][0];ij++)
					{
						dp[a[j][ij]]=min(dp[a[j][ij]],dp[qq.front()]+atime[j][qq.front()]+atime[j][ij]);
						qq.push(ij);
					}
				}
			}
			qq.pop();
		}
		cout<<dp[ren[i]]+v[ren[i]];
	}  
	return 0;
}







//我就不理解哪里越界了 没问题啊看着 怎么一直322122挖去了
//2026.10.31 
//满怀信心做t2发现啥也出不出来 得了就这样了 
//话说HB有人做迷惑行为吗。luoguID dida233 
//t1写的像史纯骗分
//t2写了半天一直报错 没招了-s估计爆0了
//t3t4是我能看的东西吗。。
//突然忘了自己-j的解除同步有没有写ios了wok别整我。。。 
//算鸟算鸟AFO了 整文化课去了 信奥高中有缘再见吧
//Lime lemonade jam nb... llz nb...
