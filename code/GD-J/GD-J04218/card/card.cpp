#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 5e5+5, maxm = 3e5+5;

/*
题意:
有长度为 n(2 <= n <= 5e5) 的纸牌数组 a (1 <= ai <= m) (1 <= m <= 3e5) 
现在进行 n 轮独立的游戏, 在第 i 轮中, ai,ai+1,...,an参与游戏
依次将第 j(i <= j <= n) 个纸牌打出到栈, 设这张牌牌面是 k (k = a[j]) 
如果栈里有 k, 将这张以及后面所有的牌扔掉
然后把 k 塞入栈中
问: 点数为 t 的牌 (1 <= t <= m) 在所有 n 局游戏中，有多少局结束时栈里留有点数为 t 的牌。 
*/

int n,m;
int a[maxn];
bool h[maxm]; // 栈里有没有这个牌
int ans[maxm];

void play(int x)
{
	stack<int> s;
	for(int i=x;i<=n;i++)
	{
		int k = a[i];
		if(h[k]) 
		{
			while(!s.empty() && s.top() != k)
			{
				int t = s.top();
				s.pop();
				h[t] = 0;	
			}
			// 现在顶牌是 k, 还要再 pop 一次
			// 但是等会又会放进来, 因此实际上不需要 pop 
		}
		else 
		{
			s.push(k);
			h[k] = 1;
		}
	}
	while(!s.empty())
	{
		int t = s.top();
		ans[t]++;
		h[t] = 0;
		s.pop();	
	}
} 

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) play(i);
	for(int i=1;i<=m;i++) 
	{
		cout<<ans[i];
		if(i != m) cout<<" ";
	}
	
	return 0;
} 
