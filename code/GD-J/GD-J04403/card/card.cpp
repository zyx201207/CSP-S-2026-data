#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
const int INF = 0x3f3f3f3f;

int n , m;
int c[N],cnt[N];
bool vis[N];
queue<int> a;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	for(int i = 1;i <= n;i++)//局数 
	{
		memset(vis,0,sizeof(vis));
		int len=0;
		for(int j = i;j <= n;j++)//枚举每个牌 
		{
			if(!vis[c[j]])//没出过相同牌 
			{	
				vis[c[j]] = 1;
			}				
			else//移走右侧牌 
			{	
				int tmp=0;
				while(a.front() != c[j])
				{
					int top = a.front();
					a.pop();
					a.push(top);
					tmp++;
				}
				while(len > tmp)
				{
					int top = a.front();
					a.pop();
					vis[top] = 0;
					len--;
				}
			}
			len++;
			a.push(c[j]);//打牌 	
		}
		while(!a.empty())//清空桌面 
		{
			int top = a.front();
			a.pop();
			cnt[top]++;	
//			cout << top << " "; 
		}	
//		cout << endl;
	} 
	for(int i = 1;i <= m;i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;	
} 
