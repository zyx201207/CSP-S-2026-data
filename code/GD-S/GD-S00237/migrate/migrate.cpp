#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=2e6+5;
int c,t;
int n;
LL d,x[N];
namespace sub123
{
	int l[N],f[5005],g[5005];
	deque <int> q;
	int tong[5005];
	void add(int x,int k)
	{
		tong[x]+=k;
	}
	void main()
	{	
		for(int i=1,j=1;i<=n;i++)
		{
			while(x[i]-x[j]>d && j<i) j++;
			l[i]=j;
	//		cout<<l[i]<<" ";
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			q.push_back(i);
			f[i]=0,g[i]=1;
			add(f[i],g[i]);
			for(int j=i+1;j<=n;j++)
			{
				f[j]=g[j]=0;
				while(!q.empty() && q.front()<l[j])
				{
					int id=q.front();
					add(f[id],-g[id]);
					q.pop_front();
				}
				if(!q.empty())
				{
					f[j]=f[q.front()]+1;
					g[j]=tong[f[q.front()]];
				}else continue;
//				cout<<i<<" "<<j<<" "<<f[j]<<" "<<g[j]<<"\n";
				if(g[j]>2) g[j]=3;
				else if(g[j]==2) cnt++;
				if(g[j]==2)
				{
					cout<<i<<" "<<j<<"\n";
				}
				while(!q.empty() && f[q.back()]>f[j])
				{
					int id=q.back();
					add(f[id],-g[id]);
					q.pop_back();
				}
				add(f[j],g[j]);
				q.push_back(j);
			}
			//最后清空记得 
			while(!q.empty())
			{
				int id=q.front();
				add(f[id],-g[id]);
				q.pop_front();
			}
		}
		cout<<cnt<<"\n";
		return ;
	}
}
namespace subA
{
	void main()
	{
		LL dd=x[2]-x[1];
		LL k=d/dd,kua=k*2;
		if(k==1) cout<<"0\n";
		else if(d<dd) cout<<"0\n";
		else cout<<max((LL)n-kua+1,0ll)<<"\n"; 
	}
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(n==1)
	{
		cout<<"0\n";
		return ;
	}
	if(c<=10)
	{
//		cout<<"a";
		sub123::main();
		return ;
	}
	if(c>=11 && c<=12)
	{
		subA::main();
		return ;
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*



0 1
4 2
1 2 3 4


0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


提交前检查：
ll.
ce. re. /0 越界
多测清空
算空间！

*/

