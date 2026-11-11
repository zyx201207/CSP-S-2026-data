//该解法满足测试点20,21的约束条件 
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int maxn=1005;
int c,n,m,d,q;
int w[maxn],k[maxn];
vector<int> g[maxn];
int t[maxn][maxn];
int flag[maxn];
vector<int> st;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++)
	{
		cin >> k[i];
		for(int j=1;j<=k[i];j++)
		{
			int A,T;
			cin >> A >> T;
			t[A][i]=T;
			if(flag[A]!=0)
			{
				st.push_back(A);
				flag[A]=3;
			}
			else flag[A]=i;
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		if(flag[x]==3 && flag[y]==3)
		{
			int sum=max(t[x][1]+t[y][1],t[x][2]+t[y][2]);
			cout << sum+w[x]+w[y] << '\n';
		}
		else if(flag[x]==3 || flag[y]==3)
		{
			if(flag[x]==3)cout << w[x]+w[y]+t[x][flag[y]]+t[y][flag[y]] << '\n';
			else cout << w[x]+w[y]+t[x][flag[x]]+t[y][flag[x]] << '\n';
		}
		else if(flag[x]==flag[y])
		{
			cout << w[x]+w[y]+t[x][flag[x]]+t[y][flag[y]] << '\n';
		}
		else if(flag[x]!=flag[y])
		{
			int minv=1e9;
			int siz=st.size();
			for(int uu=0;uu<siz;uu++)
			{
				int u=st[uu];
				minv=min(minv,t[u][1]+t[u][2]);
			}
			cout << w[x]+w[y]+t[x][flag[x]]+t[y][flag[y]]+minv << '\n';
		}
	}
	return 0;
}
