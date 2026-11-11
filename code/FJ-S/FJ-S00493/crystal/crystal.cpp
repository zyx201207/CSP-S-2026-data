//厕所捡到了一张小卡片
//突然发现封面是兄弟
//兄弟原来是个小能量
//兄弟哭着求我别说出去
//我只好先调查一下兄弟
//兄弟尝到了巨龙的力量
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ifstream cin("crystal.in",ios::in);
//	ofstream cout("crystal.out",ios::out);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//我先推导合成水晶需要能量值的计算方法，然后验证算法在 n=5*10^5 时的表现。
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	//关键性质已经找到：将初始能量值排序后，可能相同的水晶只能来源于前方，我正在编写代码，并使用样例进行测试。
	sort(a.begin()+1,a.end());
	vector<int>c(n+1,0);
	for(int i=1;i<=n;i++) c[i]=a[n]-a[i],c[i]+=c[i-1];
	auto calc=[&](int l,int r)->int
	{
		return (c[r]-c[l-1])-(r-l+1)*(a[n]-a[r]);
	};
	//我还发现随着钦定相同的点的后移，合法的最左侧区间不降，运用性质可以将复杂度优化到 O(n)，我正在补全最后的代码实现。
	int res=0;
	for(int i=1,j=1;i<=n;i++)
	{
		while(calc(j,i)>m) j++;
		res=max(res,i-j+1);
	}
	cout<<res<<endl;
	//程序已完成，并通过你给的全部 4 组样例测验，复杂度为 O(n)，并且使用 long long 防止数据溢出。
	//14: 52 [] Like [] Copy
	return 0;
}
