#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10,inf = 1e18;
int x,y,t,n,d,a[N],b[N],c[N],f[N],g[N],C[N],ans,mx,mx1,l,r,mid,op; 
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> x >> t;
	while(t--)
	{
		cin >> n >> d; ans = 0;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++)
		{
			l = i,r = n; b[i] = i;
			while(l <= r) 
			{
				mid = ((l+r)>>1);
				if(a[mid]-a[i] <= d) b[i] = mid,l = mid+1;
				else r = mid-1;
			} l = 1,r = i; c[i] = i;
			while(l <= r) 
			{
				mid = ((l+r)>>1);
				if(a[i]-a[mid] <= d) c[i] = mid,r = mid-1;
				else l = mid+1;
			}
		}
		if(11 <= x && x <= 12)
		{
			y = b[1]-1; ans = 0;
			if(y != 0 && y != 1)
			for(int i = 1;i <= n;i++)
			{
				if(b[i] == n) break;
				if(i+y*2-1 <= n) ans++;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(13 <= x && x <= 14)
		{
			op = 0;
			for(int i = 1;i <= n;i++)
			{
				if(c[i] == 1 && b[i] == n)
				{
					op = i;
					break;
				}
			}
			if(op == 1 || op == n)
			{
				cout<<0<<'\n';
				continue;
			}
			l = 0,r = 0;
			for(int i = op+1;i <= n;i++) if(c[i] == op-1) C[i] = 1;
			for(int i = n;i > op;i--) C[i] += C[i+1];
			for(int i = 1;i < op;i++) 
			{
				if(b[i] == op+1) ans += (n-b[i])-C[b[i]+1];
				if(b[i] == op) ans += C[b[i]+1];
			}
			for(int i = 1;i <= n;i++) C[i] = 0;
			cout<<ans<<'\n';
			continue;
		}
		for(int i = 1;i <= n;i++)
			{
				if(b[i] == n) break;
				for(int j = i;j <= n;j++) f[j] = inf,g[j] = 0;
				g[i] = 1,f[i] = 0; 
				for(int j = i+1;j <= n;j++)
				{
					for(int z = j;z >= i;z--)
						if(a[j]-a[z] <= d)
						{
							if(f[j] > f[z]+1) f[j] = f[z]+1,g[j] = g[z];
							else if(f[j] == f[z]+1) g[j] += g[z]; 
						}
						else break;
					if(g[j] == 2) ans++;//,cout<<i<<" ** "<<j<<'\n';
				}
			//	cout<<a[i]<<" **"<<i<<" "<<ans<<'\n';
			}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
以我的翻译，就是说一定是从u到v，经过之间的点，
求恰好的话，额，对于a,b,c,d
如果b能到d，a能到c 
那么一定存在三条,a->c->d，a->b->d，a->b->c->d 
a->b->c->d，a->b->d，所以a不能到c才行
那就有且仅有一个能够跨点才行
判断有解的话很简单，只需要满足任意两点距离<=d即可
求总数的话分治？n^2很容易
先找到左右两边第一个满足那个的，再找到第二个的，没有就是空(a_{i+2}-a_i <= k)
再找第一个不满足(a_i <= a_{i+1}的)
合并的时候也没几个好看的，也就中间几个看一下
我们存的话，只需要存左边前两个和右边前两个即可
然后就好了耶 
*/
