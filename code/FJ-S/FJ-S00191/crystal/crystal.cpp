#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ioimprove(); ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE(x); freopen(x".in","r",stdin);freopen(x".out","w",stdout);
int a[514514],n,m,maxn = 1,lst[514514][22];//lst[i][j] 表示 i 往前 2 ^ j - 1 个数都选的代价
int qpow(int a,int b)
{
	if(b == 0) return 1;
	if(b == 1) return a;
	int res = qpow(a,b / 2);
	if(b & 1) return res * res * a;
	return res * res;
}
int log2(int x)
{
	return (int)(log(x) / log(2));
}
signed main()
{
	ioimprove();
	FILE("crystal");
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= 20;i++)
		for(int j = 1;j <= n;j++)
		{
			if(j - qpow(2ll,i) < 0) continue;
			lst[j][i] = lst[j][i - 1] + lst[j - qpow(2ll,i - 1)][i - 1] + qpow(2ll,i - 1) * (a[j] - a[j - qpow(2ll,i - 1)]);
		}
	for(int i = 2;i <= n;i++)
	{
		int now = i,sum = 0;
		while(now > 0 && sum <= m)
		{
			int f = 0;
			for(int j = (int)(log2(now));j >= 0;j--) 
				if(sum + lst[now][j] + (a[i] - a[now]) * qpow(2ll,j) <= m) {/*cerr<<j<<" ",*/sum += lst[now][j] + (a[i] - a[now]) * qpow(2ll,j),now -= qpow(2ll,j);f = 1;break;}
			if(!f) break;
		}
		maxn = max(maxn,i - now);
		//cerr<<i<<" "<<now<<"\n";
	}
	cout<<maxn;
	
	return 0;
}
//二分不会写写倍增吧 
//时隔两年，我终于又通过了 T1 
//没错，如果你有看去年 FJ 猎奇代码大赏（真的有吗？），我就是去年做不出 T1 要宣布退役的那个 
//能赢吗？ 






//张雪峰老师，我还记得你！
//1217king 老师的 et magnet 保佑我 pls 
